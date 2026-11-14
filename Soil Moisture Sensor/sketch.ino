#include <WiFi.h>
#include <ThingSpeak.h>

#define MOISTURE_PIN 34
#define RED_LED      26
#define GREEN_LED    27

const char* ssid     = "Wokwi-GUEST";
const char* password = "";

unsigned long channelID = 0000000;            // your NEW channel's ID
const char* apiKey = "YOUR_WRITE_API_KEY";    // your NEW channel's Write key

const int DRY_VALUE = 4095;   // pot fully "dry"
const int WET_VALUE = 0;      // pot fully "wet"
const int DRY_LIMIT = 30;     // below 30% = too dry

WiFiClient client;

void setup() {
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  ThingSpeak.begin(client);
}

void loop() {
  int raw = analogRead(MOISTURE_PIN);
  int moisture = map(raw, DRY_VALUE, WET_VALUE, 0, 100);
  moisture = constrain(moisture, 0, 100);

  Serial.printf("Moisture: %d%%\n", moisture);

  if (moisture < DRY_LIMIT) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    Serial.println("ALERT: Soil too dry!");
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }

  ThingSpeak.setField(1, moisture);
  int code = ThingSpeak.writeFields(channelID, apiKey);
  Serial.println(code == 200 ? "Sent OK" : "Send failed: " + String(code));

  delay(20000);   // wait 20 s before next reading
}