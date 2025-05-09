# ML-IoT-Health-Monitoring-System

This SmartHealth Monitoring System is a two-part project combining IoT-based real-time health tracking with an ML-powered medical recommendation engine. This system is designed to remotely monitor patient vitals, detect emergencies like falls, and provide personalized health insights through machine learning.

# Project Structure 📁

📦 IoT-Firmware:
   
  1.  This folder contains the embedded C/C++ code for the ESP32/ESP8266 microcontrollers. The firmware:

  2.  Collects health data using sensors (heart rate, temperature, motion, GPS)

  3.  Displays vitals on a TFT screen

  4.  Sends data to the ThingSpeak cloud for monitoring

  5.  Detects falls and triggers real-time alerts via the Blynk mobile app


🤖 ML-HealthAssistant :
   
  1. This folder includes the Python-based machine learning module. It provides:

  2. Disease prediction from user-input symptoms and/or IoT sensor data

  3. Medication recommendations based on predicted conditions

  4. Personalized diet and fitness guidance

  5. A Flask-based web application for user interaction


🧩 System Integration
These two modules can work independently or together:

Standalone: ML module can accept manual input for personal health analysis.

Integrated: IoT device sends real-time data to the ML engine for automated prediction and feedback.


🛠 Technologies Used

1. ESP32 / ESP8266 (Arduino)

2. DHT22, Pulse Sensor, MPU6050, GPS

3. ThingSpeak, Blynk

4. Python, Flask, scikit-learn
