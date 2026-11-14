#include <WiFi.h>
#include <ThingSpeak.h>

#define SENSOR1_PIN 17
#define SENSOR2_PIN 27

const float DISTANCE_CM = 20.0;          // gap between the two sensors

const char* ssid     = "Wokwi-GUEST";
const char* password = "";

unsigned long channelID = 3579040;               // your NEW channel's ID
const char* apiKey = "write_api";       // your NEW channel's Write key

WiFiClient client;
unsigned long lastSend = 0;

void sendToThingSpeak(float speedKmh) {
  if (lastSend != 0 && millis() - lastSend < 15000) {
    Serial.println("Upload skipped (ThingSpeak free tier: 1 update / 15 s)");
    return;
  }
  ThingSpeak.setField(1, speedKmh);
  int code = ThingSpeak.writeFields(channelID, apiKey);
  Serial.println(code == 200 ? "Sent OK" : "Send failed: " + String(code));
  lastSend = millis();
}

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR1_PIN, INPUT_PULLUP);
  pinMode(SENSOR2_PIN, INPUT_PULLUP);

  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  ThingSpeak.begin(client);
  Serial.println("Speed monitor armed. Waiting for vehicle...");
}

void loop() {
  // Wait for sensor 1
  if (digitalRead(SENSOR1_PIN) == LOW) {
    unsigned long t1 = micros();
    Serial.println("Sensor 1 triggered");

    // Wait for sensor 2 (give up after 10 s)
    unsigned long waitStart = millis();
    while (digitalRead(SENSOR2_PIN) != LOW) {
      if (millis() - waitStart > 10000) {
        Serial.println("Timeout: sensor 2 not triggered");
        return;
      }
      delay(1);
    }
    unsigned long t2 = micros();

    float elapsed = (t2 - t1) / 1000000.0;          // seconds
    if (elapsed > 0) {
      float speedMs  = (DISTANCE_CM / 100.0) / elapsed;   // m/s
      float speedKmh = speedMs * 3.6;
      Serial.printf("Time: %.3f s  Speed: %.2f km/h\n", elapsed, speedKmh);
      sendToThingSpeak(speedKmh);
    }

    // Wait until both buttons are released, then cool down
    while (digitalRead(SENSOR1_PIN) == LOW || digitalRead(SENSOR2_PIN) == LOW) {
      delay(10);
    }
    delay(1000);
  }
}
