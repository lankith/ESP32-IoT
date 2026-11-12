
#define BLYNK_TEMPLATE_ID "enter template id"
#define BLYNK_TEMPLATE_NAME "ESP32 IoT Light Control"
#define BLYNK_AUTH_TOKEN "enter token"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define LED_PIN 5

// Receive commands from Blynk Virtual Pin V0
BLYNK_WRITE(V0)
{
  int value = param.asInt();

  digitalWrite(LED_PIN, value);

  if (value == 1)
  {
    Serial.println("LIGHT ON");
  }
  else
  {
    Serial.println("LIGHT OFF");
  }
}

void setup()
{
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.println("Connecting to WiFi...");

  WiFi.begin(ssid, pass, 6);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");

  Blynk.config(BLYNK_AUTH_TOKEN);

  Serial.println("Connecting to Blynk Cloud...");

  if (Blynk.connect())
  {
    Serial.println("Blynk Connected Successfully!");
  }
}

void loop()
{
  Blynk.run();
}
