#include "Main.h"

void setup() {
  initDebug();
  initWifi();
  initOTA();
}

void loop() {
  handleOTA();
}
