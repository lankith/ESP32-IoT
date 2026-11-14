#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ThingSpeak.h>

#define PIR_PIN 4
#define LED_PIN 5

const char* ssid     = "Wokwi-GUEST";
const char* password = "";

const char* telegramToken  = "9163369641:AAEmGcvqFMNpIeZvjbH3PSPXFG7_Z1VZejM";
const char* telegramChatId = "1267964999";

unsigned long channelID = 3579040;               // your NEW channel's ID
const char* apiKey = "I9OAARR49DBVSIWW";       // your NEW channel's Write key

const unsigned long cooldown = 20000;            // 20 s between alerts
unsigned long lastAlert = 0;
int motionCount = 0;

WiFiClient tsClient;

void sendTelegram() {
  WiFiClientSecure client;
  client.setInsecure();                          // skip SSL check (demo only)

  HTTPClient http;
  String url = "https://api.telegram.org/bot" + String(telegramToken) +
               "/sendMessage?chat_id=" + String(telegramChatId) +
               "&text=Motion%20detected!%20Event%20no.%20" + String(motionCount) +
               "%20at%20uptime%20" + String(millis() / 1000) + "%20s";

  http.begin(client, url);
  int code = http.GET();
  Serial.println("Telegram response: " + String(code));
  http.end();
}

void logToCloud() {
  int code = ThingSpeak.writeField(channelID, 1, motionCount, apiKey);
  Serial.println(code == 200 ? "Cloud log: Sent OK" : "Cloud log failed: " + String(code));
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
  Serial.println(" Connected!");

  ThingSpeak.begin(tsClient);
  Serial.println("Security system armed.");
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {
    digitalWrite(LED_PIN, HIGH);

    if (lastAlert == 0 || millis() - lastAlert > cooldown) {
      motionCount++;
      Serial.println("Motion detected! Event " + String(motionCount));
      sendTelegram();
      logToCloud();
      lastAlert = millis();
    }
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(200);
}