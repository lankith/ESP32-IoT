#include <WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h> 

#define DHTPIN  4
#define DHTTYPE DHT22

const char* ssid     = "Wokwi-GUEST";   // Wokwi's built-in Wi-Fi
const char* password = "";              // no password

unsigned long channelID = enter ID;               // your ThingSpeak Channel ID
const char* apiKey ="enter api key";       // your Write API Key

const float TEMP_ALERT = 35.0;          // serial alert threshold (°C)

WiFiClient client;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(ssid, password, 6);        // channel 6 = faster in Wokwi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  ThingSpeak.begin(client);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Sensor read failed!");
    delay(2000);
    return;
  }

  Serial.printf("Temp: %.1f C  Humidity: %.1f %%\n", t, h);

  if (t > TEMP_ALERT) {
    Serial.println("ALERT: Temperature above threshold!");
  }

  ThingSpeak.setField(1, t);
  ThingSpeak.setField(2, h);
  int code = ThingSpeak.writeFields(channelID, apiKey);
  Serial.println(code == 200 ? "Sent OK" : "Send failed: " + String(code));

  delay(15000);                         // ThingSpeak free tier: 1 update / 15 s
}
