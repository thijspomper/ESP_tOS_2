#include "OTA.h"

void initOTA(){
  if(oTA){
    ArduinoOTA.setHostname(deviceName);
    ArduinoOTA.onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH) {
        type = "sketch";
      } else { // U_FS
        type = "filesystem";
      }
  
      // NOTE: if updating FS this would be the place to unmount FS using FS.end()
      writeDebug("Start updating " + type);
    });
    ArduinoOTA.onEnd([]() {
      writeDebug("\nEnd");
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    });
    ArduinoOTA.onError([](ota_error_t error) {
      if (error == OTA_AUTH_ERROR) {
        writeDebug("Auth Failed");
      } else if (error == OTA_BEGIN_ERROR) {
        writeDebug("Begin Failed");
      } else if (error == OTA_CONNECT_ERROR) {
        writeDebug("Connect Failed");
      } else if (error == OTA_RECEIVE_ERROR) {
        writeDebug("Receive Failed");
      } else if (error == OTA_END_ERROR) {
        writeDebug("End Failed");
      }
    });
    ArduinoOTA.begin();
  }
}

void handleOTA(){
  if(oTA){
    ArduinoOTA.handle();
  }
}
