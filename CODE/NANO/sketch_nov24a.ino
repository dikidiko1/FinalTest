#include <ArduinoJson.h>

// 가변저항 핀 배열
const int potPins[] = {A0, A1, A2, A3, A6};
const int numPots = sizeof(potPins) / sizeof(potPins[0]);

void setup() {
  Serial.begin(9600); // ESP8266과 UART 통신
  for (int i = 0; i < numPots; i++) {
    pinMode(potPins[i], INPUT); // 가변저항 핀을 입력으로 설정
  }
  Serial.println("Arduino Nano Ready");
}

void loop() {
  // 가변저항 값 읽기
  int potValues[numPots];
  for (int i = 0; i < numPots; i++) {
    potValues[i] = analogRead(potPins[i]);
  }

  // JSON 데이터 생성
  StaticJsonDocument<256> doc;
  JsonArray potArray = doc.createNestedArray("potValues");
  for (int i = 0; i < numPots; i++) {
    potArray.add(potValues[i]);
  }

  // JSON 데이터 UART로 송신
  serializeJson(doc, Serial);
  Serial.println(); // 줄바꿈 추가 (ESP8266에서 데이터 구분)

  delay(500); // 0.5초 대기
}
