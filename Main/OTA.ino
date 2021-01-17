#include "OTA.h"

void initOTA(){
  if(ota){
    ArduinoOTA.onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH) {
        writeDebug("[OTA]: Received sketch");
      } else {
        writeDebug("[OTA]: Received filesystem");
      }
    });
    ArduinoOTA.onEnd([]() {
      writeDebug("[OTA]: Finished, rebooting");
    });
    ArduinoOTA.onError([](ota_error_t error) {
      if (error == OTA_AUTH_ERROR) {
        writeDebug("[OTA]: Auth Failed");
      } else if (error == OTA_BEGIN_ERROR) {
        writeDebug("[OTA]: Begin Failed");
      } else if (error == OTA_CONNECT_ERROR) {
        writeDebug("[OTA]: Connect Failed");
      } else if (error == OTA_RECEIVE_ERROR) {
        writeDebug("[OTA]: Receive Failed");
      } else if (error == OTA_END_ERROR) {
        writeDebug("[OTA]: Failed");
      }
    });
    ArduinoOTA.setHostname(deviceName);
    ArduinoOTA.begin();
  }
}

void handleOTA(){
  if(ota){
    ArduinoOTA.handle();
  }
}
