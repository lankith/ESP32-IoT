#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

const char* ssid     = "Wokwi-GUEST";
const char* password = "";

const char* iftttKey = "jPImvaqT9n1i8AfsJ5QYoZK33raLrIPmFmGjUBjhkuM";
const char* eventName = "motion_detected";

#define PIR_PIN 4
#define LED_PIN 5

unsigned long lastAlert = 0;
const unsigned long cooldown = 30000;   // 30 s between alerts

void sendAlert() {
  WiFiClientSecure client;
  client.setInsecure();                 // skip SSL check (demo only)

  HTTPClient http;
  String url = "https://maker.ifttt.com/trigger/" + String(eventName) +
               "/with/key/" + String(iftttKey);

  http.begin(client, url);
  http.addHeader("Content-Type", "application/json");
  int code = http.POST("{\"value1\":\"Motion detected!\"}");
  Serial.println("IFTTT response: " + String(code));
  http.end();
}

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi connected. System armed.");
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {
    digitalWrite(LED_PIN, HIGH);

    if (lastAlert == 0 || millis() - lastAlert > cooldown) {
      Serial.println("Motion detected! Sending alert...");
      sendAlert();
      lastAlert = millis();
    }
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(200);
}