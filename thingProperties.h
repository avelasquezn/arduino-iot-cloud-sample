#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[] = "f9fab6b1-5ed6-42ac-9855-735a4d24e10a";

const char SSID[] = "Wokwi-GUEST";
const char PASS[] = "";
const char DEVICE_KEY[] = "NLTV0ICAM2S8IUTN5UYO";

void onMinimalTemperatureChange();
void onCurrentTemperatureChange();

float minimalTemperature;
float currentTemperature;

void initProperties() {
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(minimalTemperature, READWRITE, ON_CHANGE, onMinimalTemperatureChange);
  ArduinoCloud.addProperty(currentTemperature, READWRITE, ON_CHANGE, onCurrentTemperatureChange);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);