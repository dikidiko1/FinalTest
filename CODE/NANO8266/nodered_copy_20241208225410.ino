#include <Wire.h>
#include <MPU6050.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>

// Wi-Fi & MQTT 설정
const char* ssid = "";
const char* password = "";
const char* mqtt_server = "";
const int mqtt_port = 1883;

// MQTT 토픽
const char* outTopic = "";

// MPU6050 설정
MPU6050 mpu(0x68);

// SoftwareSerial 설정 (Nano와 UART 통신)
#define NANO_RX_PIN D5 // ESP8266 RX 연결 (Nano의 TX)
#define NANO_TX_PIN D6 // ESP8266 TX 연결 (Nano의 RX)
SoftwareSerial nanoSerial(NANO_RX_PIN, NANO_TX_PIN);

WiFiClient espClient;
PubSubClient client(espClient);

String nanoData = "";
bool newNanoData = false;

// Wi-Fi 연결 설정
void setupWiFi() {
  Serial.print("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

// MQTT 설정
void setupMQTT() {
  client.setServer(mqtt_server, mqtt_port);
}

void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP8266_MPU_Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.println(client.state());
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(9600);       // 디버깅용
  nanoSerial.begin(9600);   // Nano와 소프트웨어 시리얼 설정

  // Wi-Fi 연결
  setupWiFi();

  // MQTT 설정
  setupMQTT();

  // MPU6050 초기화
  Wire.begin();
  mpu.initialize();
  if (mpu.testConnection()) {
    Serial.println("MPU6050 연결 성공!");
  } else {
    Serial.println("MPU6050 연결 실패!");
  }
}

void loop() {
  if (!client.connected()) {
    reconnectMQTT();
  }
  client.loop();

  // MPU6050 데이터 읽기
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getRotation(&gx, &gy, &gz);

  // JSON 생성 및 MQTT 전송
  StaticJsonDocument<512> doc;
  doc["ax"] = ax;
  doc["ay"] = ay;
  doc["az"] = az;
  doc["gx"] = gx;
  doc["gy"] = gy;
  doc["gz"] = gz;

  // 나노 데이터 수신
  while (nanoSerial.available()) {
    char c = nanoSerial.read();
    if (c == '\n') { // 데이터를 한 줄로 수신
      Serial.print("Received from Nano: ");
      Serial.println(nanoData);

      // 나노 데이터 파싱
      StaticJsonDocument<256> nanoDoc;
      DeserializationError error = deserializeJson(nanoDoc, nanoData);
      if (!error) {
        // 나노 데이터 추가
        doc["potValues"] = nanoDoc["potValues"];
        Serial.println("Nano data added to MQTT message");
      } else {
        Serial.print("Failed to parse JSON from Nano: ");
        Serial.println(error.c_str());
      }

      nanoData = ""; // 버퍼 초기화
    } else {
      nanoData += c;
    }
  }

  // MQTT 발행
  char jsonBuffer[512];
  serializeJson(doc, jsonBuffer);
  if (client.publish(outTopic, jsonBuffer)) {
    Serial.println("Published data: ");
    Serial.println(jsonBuffer);
  } else {
    Serial.println("MQTT Publish Failed");
  }

  delay(500);
}
