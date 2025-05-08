# IoT-Firmware (Smart Health Monitoring System)
This firmware is designed for the SmartHealth IoT Monitoring Project, developed using ESP32 and ESP8266 microcontrollers. It continuously monitors patient vitals, displays data in real-time, sends it to the cloud (ThingSpeak), and triggers emergency alerts through the Blynk platform when a fall is detected.

🔧 Key Features

💡 Real-Time Monitoring:

 1. Measures heart rate (BPM) and body temperature.

 2. Detects motion and falls using an accelerometer and gyroscope.

 3. Tracks location via GPS.

 4. Displays health data on a TFT screen.

☁️ Cloud Integration:

 1. Sends temperature, BPM, latitude, and longitude to ThingSpeak for remote health monitoring.

 2. Uses Wi-Fi for real-time data transfer.

🚨 Emergency Alerts:

 1. Fall detection activates a buzzer and sends alert data to ESP8266 via serial communication.

 2. The alert system is designed to immediately notify caregivers.

📲 Blynk Notifications:

 1. If a fall is detected, ESP8266 sends a notification to the Blynk mobile app.

 2. Includes a live Google Maps link to the patient's location.

# Hardware Components Used

1. ESP32 microcontroller (sensor handling and data transmission)

2. ESP8266 microcontroller (Blynk alerts)

3. Pulse sensor (simulated for heart rate input)

4. DHT22 sensor (body temperature)

5. MPU6050 (motion and fall detection)

6. GPS module (location tracking)

7. TFT display (for real-time health info)

8. Buzzer (audio alert for fall detection)

9. Li-Ion battery (portable power)

![project](https://github.com/user-attachments/assets/5621efcd-0b81-479c-a404-9e6fb35b2ba1)



# How the System Works
1️⃣ Sensor Data Collection (ESP32)
The ESP32 is the brain of the system. It reads data from:

1. A DHT22 sensor for body temperature.

2. A pulse sensor for estimating heart rate (simulated using analog input).

3. An MPU6050 accelerometer and gyroscope to detect sudden motion or falls.

4. A GPS module to get the current location.

5. It also displays key information (temperature and BPM) on a TFT screen for local monitoring.

2️⃣ Fall Detection Logic:

1. The MPU6050 monitors acceleration in X and Y directions.

2. If acceleration crosses a certain threshold (e.g., a sudden jerk or strong tilt), it's considered a fall.

3. When a fall is detected, the ESP32:

4. Activates a buzzer or speaker to alert people nearby.

5. Sends the GPS coordinates and fall flag to ESP8266 via serial communication.

3️⃣ Cloud Data Upload (ThingSpeak)

1. The ESP32 connects to Wi-Fi and uploads temperature, heart rate, and location data to ThingSpeak, a cloud platform.

2. This enables remote access to live patient data from any browser or mobile device using the ThingSpeak dashboard.

3. Each parameter (temperature, BPM, latitude, longitude) is uploaded in a separate field.

4️⃣ Alert and Notification System (ESP8266 + Blynk)

1. The ESP8266 listens to data from the ESP32 via a serial connection.

2. It checks if a fall has occurred by reading the third value (fall flag).

3. If a fall is detected:

   1. A fall alert notification is sent to the Blynk mobile app.

   2. It includes a Google Maps link with the patient’s live GPS location.

   3. The buzzer remains active to signal danger locally.

4. If no fall is detected, the buzzer is turned off to conserve power and prevent false alarms.

5️⃣ User Monitoring and Response

1. Local Monitoring: Family or caretakers can see vitals directly on the TFT screen.

2. Remote Monitoring: Authorized people can log in to ThingSpeak to check vitals in real-time.

3. Emergency Response: If a fall is detected, caregivers receive:

4. A notification via Blynk.

5. A clickable map link showing exactly where the person fell.

   ![project img 2](https://github.com/user-attachments/assets/7c90621c-92a6-4e24-a873-3dbcb786e61c)



