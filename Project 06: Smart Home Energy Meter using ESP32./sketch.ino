#include <WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ThingSpeak.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define CURRENT_PIN 34

const float MAX_CURRENT = 20.0;     // ACS712-20A range: 0-20 A
const float VOLTAGE     = 220.0;    // mains voltage
const int   SAMPLES     = 100;      // readings averaged for a stable value

const char* ssid     = "Wokwi-GUEST";
const char* password = "";

unsigned long channelID =3579175;               // your NEW channel's ID
const char* apiKey = "LIMCIJIHO4TY7MT6";       // your NEW channel's Write key

WiFiClient client;
unsigned long lastDisplay = 0;
unsigned long lastUpload  = 0;
bool firstUpload = true;

float readCurrent() {
  long sum = 0;
  for (int i = 0; i < SAMPLES; i++) {
    sum += analogRead(CURRENT_PIN);
    delay(1);
  }
  float avg = sum / (float)SAMPLES;
  return avg * MAX_CURRENT / 4095.0;   // 0-4095 -> 0-20 A
}

void uploadThingSpeak(float I, float P) {
  ThingSpeak.setField(1, I);
  ThingSpeak.setField(2, P);
  int code = ThingSpeak.writeFields(channelID, apiKey);
  Serial.println(code == 200 ? "Sent OK" : "Send failed: " + String(code));
}

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi");

  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  ThingSpeak.begin(client);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wi-Fi Connected");
  delay(1000);
}

void loop() {
  unsigned long now = millis();

  // Update LCD + Serial every 1 second
  if (now - lastDisplay >= 1000) {
    lastDisplay = now;

    float I = readCurrent();
    float P = I * VOLTAGE;

    char line1[17], line2[17];
    snprintf(line1, sizeof(line1), "I=%.2f A       ", I);
    snprintf(line2, sizeof(line2), "P=%.1f W       ", P);
    lcd.setCursor(0, 0); lcd.print(line1);
    lcd.setCursor(0, 1); lcd.print(line2);

    Serial.printf("Current: %.2f A  Power: %.1f W\n", I, P);

    // Upload every 30 seconds (first one right away)
    if (firstUpload || now - lastUpload >= 30000) {
      uploadThingSpeak(I, P);
      lastUpload = now;
      firstUpload = false;
    }
  }
}