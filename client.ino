#include <BLEDevice.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

BLEScan* pBLEScan;
const char* targetName = "HW7_SERVER";
float lastDistance = 0;

void setup() {
  Serial.begin(115200);
  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();
  pBLEScan->setActiveScan(true);
}

void loop() {
  BLEScanResults* results = pBLEScan->start(2, false);
  for (int i = 0; i < results->getCount(); i++) {
    BLEAdvertisedDevice d = results->getDevice(i);
    if (d.getName() == targetName) {
      int rssi = d.getRSSI();
      float txPower = -59; // 기준값
      float n = 2.0;        // 환경계수
      lastDistance = pow(10.0, (txPower - rssi) / (10 * n));
      Serial.print("RSSI: "); Serial.print(rssi);
      Serial.print(" → Distance: "); Serial.print(lastDistance);
      Serial.println(" m");
      break;
    }
  }
  pBLEScan->clearResults();
  delay(3000);
}
