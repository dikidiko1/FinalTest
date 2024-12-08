#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

// Wi-Fi & MQTT 설정
const char* ssid = "";
const char* password = "";
const char* mqtt_server = "";
const int mqtt_port = 1883;
const char* inTopic = "";

WiFiClient espClient;
PubSubClient client(espClient);

// 이전 값 저장
int prevAx = 0, prevAy = 0, prevAz = 0;
int prevPotValues[5] = {0, 0, 0, 0, 0};

// 오차 범위
const int gyroThreshold = 50;
const int potThreshold = 20;

void setupWiFi() {
  Serial.print("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("D1MiniClient")) {
      Serial.println("Connected to MQTT broker!");
      client.subscribe(inTopic);
      Serial.print("Subscribed to topic: ");
      Serial.println(inTopic);
    } else {
      Serial.print("Failed to connect, rc=");
      Serial.println(client.state());
      Serial.println("Trying again in 5 seconds...");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  payload[length] = '\0';
  String rawMessage = String((char*)payload);

  Serial.print("MQTT message received from topic: ");
  Serial.println(topic);
  Serial.print("Payload: ");
  Serial.println(rawMessage);

  StaticJsonDocument<256> doc;
  DeserializationError error = deserializeJson(doc, rawMessage);
  if (error) {
    Serial.print("Failed to parse JSON: ");
    Serial.println(error.c_str());
    return;
  }

  Serial1.println(rawMessage); // 우노로 전송
}

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  setupWiFi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    Serial.println("MQTT not connected. Reconnecting...");
    reconnectMQTT();
  }
  client.loop();
}
