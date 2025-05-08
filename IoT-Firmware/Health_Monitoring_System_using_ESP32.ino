#include <WiFi.h>
#include <ThingSpeak.h>
#include <TinyGPS.h>
TinyGPS gps;
float flat, flon;

const char *ssid = "GalaxySAM";        // Your WiFi SSID
const char *password = "11111111";  // Your WiFi Password
unsigned long myChannelNumber = 2830283;  // Replace with your channel ID
const char *myWriteAPIKey = "DNV7I9VJZ3Z5V1M5";  // Replace with your Write API Key

WiFiClient  client;

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
Adafruit_MPU6050 mpu;

#include "DHT.h"
#define DHTPIN 4     
#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>

//Pin for ESP32
  #define TFT_CS         5  //case select connect to pin 5
  #define TFT_RST        15 //reset connect to pin 15
  #define TFT_DC         32 //AO connect to pin 32  (not sure that this is really used)  try pin 25
  #define TFT_MOSI       23 //Data = SDA connect to pin 23
  #define TFT_SCLK       18 //Clock = SCK connect to pin 18

// For ST7735-based displays, we will use this call
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

int PulseSensorPurplePin = A0;  // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED13 = 13;                 //  The on-board Arduion LED


int Signal;           // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 550;  // Determine which Signal to "count as a beat", and which to ingore.

int BPM;

int voice = 12;

void setup(void) {
  Serial.begin(9600);
  pinMode(voice, OUTPUT);
  tft.initR(INITR_BLACKTAB);      // Init ST7735S chip, black tab
  dht.begin();
  pinMode(LED13, OUTPUT);
  WiFi.begin(ssid, password);
 // Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
 // Serial.println("Connected to WiFi");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

 // Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
   // Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
 // Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
 // Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
 // Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
 // Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }
digitalWrite(voice, HIGH);
}//end of void setup


/**
 Possible colors that are predefined...
 
ST7735_BLACK ST77XX_BLACK
ST7735_WHITE ST77XX_WHITE
ST7735_RED ST77XX_RED
ST7735_GREEN ST77XX_GREEN
ST7735_BLUE ST77XX_BLUE
ST7735_CYAN ST77XX_CYAN
ST7735_MAGENTA ST77XX_MAGENTA
ST7735_YELLOW ST77XX_YELLOW
ST7735_ORANGE ST77XX_ORANGE

*/

void loop() 
{
digitalWrite(voice, LOW);
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (Serial.available()) 
    {
      char c = Serial.read();
      //Serial.print(c);
      if (gps.encode(c))
      newData = true;
      break;
    }
  }
  unsigned long age;
  gps.f_get_position(&flat, &flon, &age);


float t = dht.readTemperature();

int f = dht.readTemperature(true)+15;
  
//text with wrapping
  tft.setTextWrap(true);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
   tft.print("T:");
   tft.print(f);



Signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor's value.
                                              // Assign this value to the "Signal" variable.

  if (Signal < 2000) {
    BPM = 0;
  }
  else if((Signal > 2000) && (Signal < 2500))
  {
    BPM = 72;
  }
  else if((Signal > 2500) && (Signal < 3000))
  {
    BPM = 85;

  }
  else if((Signal > 3000) && (Signal < 3500))
  {
    BPM = 92;

  }
    else if((Signal > 3500) && (Signal < 4000))
  {
    BPM = 98;
 
  }
   
 tft.setCursor(0, 50);
 
  tft.print("BPM:");
   tft.print(BPM);
 sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  /*Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");*/
  Serial.print(flat,6);
  Serial.print(",");
  Serial.print(flon,6);
  if((a.acceleration.x > 2.5) || (a.acceleration.x < -2) || (a.acceleration.y > 2.5) || (a.acceleration.y < -2))
  {
    Serial.print(",");
  Serial.println("1");
  digitalWrite(voice, LOW);
  tft.setCursor(0, 80);
 
  tft.print("  Patient ");
   tft.print("Fall down");
   delay(500);
}
else
{
      Serial.print(",");
  Serial.println("0");
  digitalWrite(voice, HIGH);
}  
 ThingSpeak.writeField(myChannelNumber, 1, f, myWriteAPIKey);
 ThingSpeak.writeField(myChannelNumber, 2, BPM, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 3, flat, myWriteAPIKey);
 ThingSpeak.writeField(myChannelNumber, 4, flon, myWriteAPIKey);


}//end of void loop
