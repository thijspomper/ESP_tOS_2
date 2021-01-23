#include "Main.h"

void setup() {
  initDebug();
  initWifi();
  initOTA();
  initMqtt();
  initTemp();
}

void loop() {
  handleMqtt();
  handleOTA();
  handleTemp();
  delay(1000);
}
