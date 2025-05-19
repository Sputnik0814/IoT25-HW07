#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

BLEScan* pBLEScan;
String targetDeviceName = "BLE_Server"; // 서버 ESP32 이름
const int scanTimeSec = 5;
int rssiSum = 0;
int count = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("BLE txPower 측정 클라이언트 시작 (1m 거리에서 실행하세요)");

  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();
  pBLEScan->setActiveScan(true);
}

void loop() {
  Serial.println("BLE 광고 스캔 중...");
  rssiSum = 0;
  count = 0;

  BLEScanResults foundDevices = pBLEScan->start(scanTimeSec, false);  // 포인터 아님

  for (int i = 0; i < foundDevices.getCount(); ++i) {
    BLEAdvertisedDevice device = foundDevices.getDevice(i);

    if (device.getName() == targetDeviceName) {
      int rssi = device.getRSSI();
      rssiSum += rssi;
      count++;

      Serial.print("RSSI 측정값: ");
      Serial.println(rssi);
    }
  }

  if (count > 0) {
    float avgRSSI = rssiSum * 1.0 / count;
    Serial.print("평균 RSSI (txPower): ");
    Serial.print(avgRSSI, 2);
    Serial.println(" dBm");
  } else {
    Serial.println("서버를 찾지 못했습니다. 이름 또는 거리 확인 필요");
  }

  pBLEScan->clearResults();
  delay(5000);
}
