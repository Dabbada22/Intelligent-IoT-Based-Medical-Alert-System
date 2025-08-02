#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = "Your_Blynk_Auth_Token";   // Get this from Blynk app
char ssid[] = "Your_WiFi_SSID";
char pass[] = "Your_WiFi_Password";

#define DHTPIN D2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define PULSE_SENSOR_PIN A0
#define BUZZER_PIN D5

BlynkTimer timer;

void sendSensorData() {
  float temp = dht.readTemperature();
  int pulse = analogRead(PULSE_SENSOR_PIN);

  // Send to Blynk
  Blynk.virtualWrite(V0, temp);     // Temp to Blynk
  Blynk.virtualWrite(V1, pulse);    // Pulse to Blynk

  // Alert conditions
  if (temp > 38.0 || pulse < 50 || pulse > 120) {
    digitalWrite(BUZZER_PIN, HIGH);
    Blynk.notify("⚠️ Medical Alert: Abnormal Vitals Detected!");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  Serial.print("Temp: "); Serial.println(temp);
  Serial.print("Pulse: "); Serial.println(pulse);
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  timer.setInterval(2000L, sendSensorData);  // every 2 seconds
}

void loop() {
  Blynk.run();
  timer.run();
}
