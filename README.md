# 🏥 Intelligent IoT-Based Medical Alert System

An IoT-based real-time health monitoring and emergency alert system designed to monitor vital signs such as heart rate and body temperature. This system automatically sends alerts to caregivers or doctors if abnormal readings are detected, potentially saving lives in critical situations.

---

## 📌 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Circuit Diagram](#circuit-diagram)
- [How It Works](#how-it-works)
- [Installation & Setup](#installation--setup)
- [Usage](#usage)
- [Applications](#applications)
- [Future Improvements](#future-improvements)
- [License](#license)
- [Contributors](#contributors)

---

## 🧠 Overview

This system is built using a NodeMCU (ESP8266) microcontroller, integrated with a pulse sensor and temperature sensor (DHT11). Data is continuously monitored and transmitted to a cloud dashboard using Blynk. When a critical condition is detected (e.g., low/high pulse or fever), a buzzer is activated and alerts are sent to a connected mobile device.

---

## ✨ Features

- Real-time temperature and heart rate monitoring
- Automatic alerts to caregivers via mobile app (Blynk)
- Local alarm using buzzer
- Wireless data transmission via Wi-Fi
- Mobile dashboard for remote access

---

## 🔌 Hardware Requirements

| Component                      | Quantity |
|--------------------------------|----------|
| NodeMCU ESP8266                | 1        |
| Pulse Sensor (KY-039/MAX30100) | 1        |
| DHT11 Temperature Sensor       | 1        |
| Buzzer                         | 1        |
| LEDs (optional)                | 2        |
| Jumper wires                   | -        |
| Breadboard                     | 1        |

---

## 💻 Software Requirements

- Arduino IDE
- Blynk Mobile App
- Blynk Libraries
- ESP8266 Board Add-on for Arduino
- Optional: IFTTT (for SMS/Email alerts)

---

## 📈 Circuit Diagram

[Pulse Sensor] ----> A0
[DHT11] ----> D2
[Buzzer] ----> D5
[WiFi] ----> NodeMCU internal


> *Please refer to the actual circuit diagram image or Fritzing file  available.*

---

## ⚙️ How It Works

1. Sensors collect real-time body temperature and heart rate data.
2. NodeMCU processes and sends the data to Blynk via Wi-Fi.
3. If vitals exceed safe thresholds:
   - Buzzer sounds an alert.
   - Notification is pushed to caregiver’s phone.
4. Live readings can be viewed on the mobile dashboard.

---

## 🛠 Installation & Setup

### 1. Arduino Code
- Install required libraries: `DHT`, `Blynk`, `ESP8266WiFi`
- Replace the placeholders in code:
  
  char auth[] = "Your_Blynk_Auth_Token";
  char ssid[] = "Your_WiFi_SSID";
  char pass[] = "Your_WiFi_Password";
Upload to NodeMCU using Arduino IDE.

2. Blynk Setup
Create a new project in Blynk App.

Add:

Gauge Widget for Temperature (V0)

Gauge Widget for Heart Rate (V1)

Notification Widget

Copy and paste your Auth Token into your Arduino code.

🧪 Usage
Power on the device.

Open Blynk app to monitor live data.

Alerts are triggered when:

Temperature > 38°C

Heart Rate < 50 bpm or > 120 bpm

Buzzer will activate and a Blynk notification is sent.

💡 Applications
Elderly care monitoring

Post-operative patient monitoring

Remote health tracking in rural areas

Emergency alert systems for chronic patients

🚀 Future Improvements
Add SpO₂ monitoring with MAX30102

Fall detection using accelerometer (e.g., MPU6050)

Integration with Google Sheets or Firebase

SMS/Email alert via IFTTT or SMTP

Battery-powered and portable model

📄 License
This project is licensed under the MIT License.

👨‍💻 Contributors
[Nagaraju] - Developer & System Integrator



Feel free to contribute or open an issue if you find bugs or want to add features.
