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
- MQTT 통신 라이브러리 (`PubSubClient`)  
- App Inventor 기반 스마트폰 앱  
- JSON 데이터 파싱 및 처리 라이브러리  

---

## 🌟 주요 기능  

1. **모드 전환**  
   - **엄지 손가락 값**(센서 값)에 따라 동작 모드 자동 전환:  
     - `930 이상`: RC 모드 (자이로 센서를 통한 차량 제어)  
     - `930 미만`: 로봇팔 모드 (손가락 별 서보모터 제어)  

2. **실시간 데이터 업데이트**  
   - MQTT를 통해 자이로 센서 값과 로봇팔 상태를 JSON 형식으로 전송  

3. **스마트폰 제어**  
   - App Inventor 기반 앱으로 모드 전환 및 센서 데이터 확인  

---

## 📂 프로젝트 구조  

```plaintext
📂 Project_RobotArm_RC
├── 📁 Code
│   ├── ESP8266_Code.ino        // ESP8266용 코드
│   ├── ArduinoUno_Code.ino     // Arduino Uno용 코드
├── 📁 Images
│   ├── system_diagram.png      // 하드웨어 시스템 다이어그램
│   ├── app_control_ui.png      // 스마트폰 앱 UI
└── README.md                   // 프로젝트 설명 파일
