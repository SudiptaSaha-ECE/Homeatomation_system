#define BLYNK_TEMPLATE_ID "TMPL3QTVQ2IAv"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "2RyccOBP3HlHli66Mj4chwjHt1Dct6a7"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WiFiManager.h> // WiFi AutoConnect Library

char auth[] = BLYNK_AUTH_TOKEN;

// Use only 2 pins: D1 (GPIO5), D2 (GPIO4)
const int pins[] = {D1, D2};
const int pinCount = 2;

void setup() {
  Serial.begin(115200);

  // Initialize pins as OUTPUT
  for (int i = 0; i < pinCount; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }

  Serial.println("ESP8266 Home Automation System Starting...");
  Serial.println("Type 'reset' in Serial Monitor to clear Wi-Fi settings.");

  long startTime = millis();
  while (millis() - startTime < 5000) {
    if (Serial.available()) {
      String command = Serial.readStringUntil('\n');
      command.trim();
      if (command == "reset") {
        Serial.println("Resetting Wi-Fi settings...");
        WiFiManager wifiManager;
        wifiManager.resetSettings();
        delay(1000);
        ESP.restart();
      }
    }
  }

  // Wi-Fi auto connect
  WiFiManager wifiManager;
  wifiManager.autoConnect("ESP8266-Setup");
  Serial.println("Connected to Wi-Fi");

  Blynk.begin(auth, WiFi.SSID().c_str(), WiFi.psk().c_str());
  Serial.println("Connected to Blynk Cloud");
}

// BLYNK WRITE HANDLER FOR 2 CHANNELS
BLYNK_WRITE(V0) { togglePin(0, param.asInt()); } // D1
BLYNK_WRITE(V1) { togglePin(1, param.asInt()); } // D2

void togglePin(int index, int state) {
  digitalWrite(pins[index], state ? HIGH : LOW);
  Serial.print("Pin ");
  Serial.print(pins[index]);
  Serial.print(" set to ");
  Serial.println(state ? "HIGH" : "LOW");
}

void loop() {
  Blynk.run();
}

