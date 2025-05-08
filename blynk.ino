

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_TEMPLATE_ID "TMPL3Nrg4G_WQ"
#define BLYNK_TEMPLATE_NAME "Health Monitoring System"
#define BLYNK_AUTH_TOKEN "mavojNrw5ra3bZ_HT3piLGMAGSurWyBO"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "GalaxySAM";  //Enter your WIFI name
char pass[] = "11111111";   //Enter your WIFI password


String lat,lag,fall;
String data;
String data1;
int voice = D0;
int FALL;
float LAT;
float LAG;

void setup() {
  Serial.begin(9600);
 pinMode(voice, OUTPUT);



 
   Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
    digitalWrite(voice, HIGH);
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.readStringUntil('\n');
    Serial.println(data);
    if (data != "\n") {
lat = getValue(data, ',', 0);
lag = getValue(data, ',', 1);
fall = getValue(data, ',', 2);




      LAT = lat.toFloat();
      LAG = lag.toFloat();
      FALL = fall.toInt();
     
    
 if(FALL == 1)
 {
   digitalWrite(voice, LOW);
Blynk.logEvent("fall" , "Person fall down");
        Blynk.logEvent("alert", "http://maps.google.com/maps?q=" + String(LAT) + "," + String(LAG));
        delay(1000);
 }
 else
 {
   digitalWrite(voice, HIGH);
 }
    
      
      data = " ";
    }
  }
  Blynk.run();
}


String getValue(String data, char seperator, int index) {
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;
  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == seperator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
