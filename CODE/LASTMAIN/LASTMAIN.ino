#include <AFMotor.h>
#include <Adafruit_PWMServoDriver.h>
#include <ArduinoJson.h>

// PCA9685 설정
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);
AF_DCMotor motor3(3, MOTOR12_64KHZ);
AF_DCMotor motor4(4, MOTOR12_64KHZ);

int wheelSpeed = 100;
bool isRobotArmMode = false; // 로봇팔 모드 상태

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino Uno Ready");

  // PCA9685 초기화
  pwm.begin();
  pwm.setPWMFreq(50);

  // DC 모터 초기화
  motor1.setSpeed(wheelSpeed);
  motor2.setSpeed(wheelSpeed);
  motor3.setSpeed(wheelSpeed);
  motor4.setSpeed(wheelSpeed);
}

void loop() {
  if (Serial.available() > 0) {
    String rawMessage = Serial.readStringUntil('\n'); // 줄 단위로 메시지 읽기
    String message = cleanMessage(rawMessage); // JSON 부분만 정제

    if (message.length() > 0) { // JSON 메시지가 올바르다면
      Serial.println(message); // 메시지만 출력
      processMessage(message); // JSON 메시지 처리
    }
  }

  delay(100); // 처리 간격 추가
}

// 메시지 정제 함수
String cleanMessage(String rawMessage) {
  int startIndex = rawMessage.indexOf("{"); // JSON 시작 위치 찾기
  int endIndex = rawMessage.lastIndexOf("}"); // JSON 끝 위치 찾기
  
  if (startIndex != -1 && endIndex != -1 && endIndex > startIndex) {
    return rawMessage.substring(startIndex, endIndex + 1); // 올바른 JSON 부분만 반환
  }
  
  return ""; // 유효하지 않은 메시지
}

// JSON 메시지 처리
void processMessage(String message) {
  StaticJsonDocument<128> doc;
  DeserializationError error = deserializeJson(doc, message);

  if (error) {
    return; // JSON 파싱 실패 시 무시
  }

  int ax = doc["ax"] | 0;
  int ay = doc["ay"] | 0;
  JsonArray potValues = doc["potValues"];

  if (potValues.isNull() || potValues.size() < 5) {
    return; // potValues 배열이 없거나 크기가 부족하면 무시
  }

  // 엄지 값 확인 (potValues 마지막 값 사용)
  int thumbValue = potValues[4];
  if (thumbValue >= 930) {
    if (!isRobotArmMode) {
      isRobotArmMode = true; // RC 모드 활성화
      Serial.println("Switched to RC Mode");
    }
  } else {
    if (isRobotArmMode) {
      isRobotArmMode = false; // 로봇팔 모드 활성화
      Serial.println("Switched to Robot Arm Mode");
    }
  }

  // 모드에 따라 동작
  if (isRobotArmMode) {
    controlRC(ax, ay); // RC 제어
  } else {
    controlRobotArm(potValues); // 로봇팔 제어
  }
}

// RC 모드 제어 함수
void controlRC(int ax, int ay) {
  if (ay > 10000) rotateLeft();
  else if (ay < -10000) rotateRight();
  else if (ax > 10000) moveBackward();
  else if (ax < -10000) moveForward();
  else stopMoving();
}

// 로봇팔 제어 함수
void controlRobotArm(JsonArray potValues) {
  int indexFinger = potValues[0]; // 검지
  int middleFinger = potValues[1]; // 중지
  int ringFinger = potValues[2]; // 약지
  int pinkyFinger = potValues[3]; // 새끼

  // 로봇팔 동작
  pwm.setPWM(0, 0, map(indexFinger, 0, 180, 150, 600)); // 검지
  pwm.setPWM(1, 0, map(middleFinger, 0, 180, 150, 600)); // 중지
  pwm.setPWM(2, 0, map(ringFinger, 0, 180, 150, 600)); // 약지
  pwm.setPWM(3, 0, map(pinkyFinger, 0, 180, 150, 600)); // 새끼
}

// 메카넘휠 제어 함수
void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void rotateLeft() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void rotateRight() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void stopMoving() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}