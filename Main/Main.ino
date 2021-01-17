#include "Main.h"

void setup() {
  initDebug();
  initWifi();
  initOTA();
  initMqtt();
}

void loop() {
  handleOTA();
  handleMqtt();
}
