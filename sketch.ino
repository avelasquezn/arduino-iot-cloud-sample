#include "thingProperties.h"
#include <Arduino.h>
#include <HTTPClient.h>
#include <iostream>

using namespace std;

const char* ssid = "Wokwi-GUEST";
const char* password = "";
HTTPClient client;




void setup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.begin(9600);
  delay(500);
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  delay(500);
  Serial.print(".");
}

void onMinimalTemperatureChange() {
  Serial.println("Minimal Change");
}

void onCurrentTemperatureChange() {
  Serial.println("Current Change");
}
