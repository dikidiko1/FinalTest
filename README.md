# FinalTest  
**IoT 기반 스마트 RC 및 로봇팔 제어 시스템**  

_"ESP8266과 MQTT, App Inventor를 활용하여 스마트폰으로 로봇팔과 RC 차량을 제어하는 혁신적인 IoT 프로젝트."_  

---

## 📖 프로젝트 개요  

이 프로젝트는 IoT 기술과 로봇 공학을 융합하여, 스마트폰을 활용한 RC 차량 및 로봇팔 제어 시스템을 구축한 프로젝트입니다.  

### 주요 목표:  
- **JSON 데이터 파싱**을 통해 실시간 센서 값을 확인  
- **MQTT 기반 원격 제어** 기능 구현  
- **자이로 센서를 활용한 RC 차량 제어 및 모드 전환**  

---

## 🛠 사용 기술  

### **하드웨어**  
- ESP8266  
- Arduino Uno  
- MG996R 및 SG90 서보모터  
- DC 모터  
- PCA9685 서보 드라이버  

### **소프트웨어**  
- MQTT 통신 라이브러리 (PubSubClient)  
- App Inventor 기반 스마트폰 앱  
- JSON 데이터 파싱 및 처리 라이브러리  

---

## 🚀 설치 및 실행 방법  

### **1. 하드웨어 설정**  
- Arduino Uno에 서보모터 및 DC 모터 연결  
- ESP8266에 MQTT 브로커 주소 및 Wi-Fi 정보 입력  

### **2. 소프트웨어 설정**  
- **Arduino IDE**  
  - 필요한 라이브러리 설치:  
    - Adafruit_PWMServoDriver  
    - PubSubClient  
    - ArduinoJson  

- **MQTT 설정**  
  - MQTT 브로커 주소: `  
  - 구독 토픽: `  

- **App Inventor 앱**  
  - JSON 데이터를 표시하고 RC/로봇팔 모드 전환 버튼 구현  

### **3. 실행 방법**  
1. Arduino 코드를 업로드  
2. ESP8266을 MQTT 브로커와 연결  
3. App Inventor 앱 실행 후 Wi-Fi 연결  

---

## 📋 예제 데이터

JSON
{
  "ax": -704,
  "ay": -1512,
  "az": 13608,
  "gx": -588,
  "gy": -1410,
  "gz": 677,
  "potValues": [6, 5, 4, 21, 1019]
}

---
## 📧 문의 및 참고자료
- 이메일: kwsktj12858@gmail.com
  # 참고 자료:
- https://www.youtube.com/watch?v=55onRTxbPg4  [Lee Curiosity] YOUTUBE
- https://youtu.be/F0ZvF-FbCr0?si=yOhaSjOO77qrbwSI [Eben Kouao] YOUTUBE
  # 3D MODEL 자료:
- EEZYbotARM MK2 by daGHIZmo on Thingiverse: https://www.thingiverse.com/thing:1454048
- [https://www.youtube.com/watch?v=TqKYJ64Kpoo] [https://www.youbionic.com/] 에서 구매
