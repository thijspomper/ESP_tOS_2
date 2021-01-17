#include "Wifi.h"

void initWifi(){
  if(wifi){
    WiFi.mode(WIFI_STA);
    WiFi.hostname(deviceName);
    WiFi.begin(wifiSsid, wifiPass);
    writeDebug("[Wifi]: Establishing connection");
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
      writeDebug("[Wifi]: Connection Failed! Rebooting");
      delay(5000);
      ESP.restart();
    }
    writeDebug("[Wifi]: Connected");
    writeDebug(WiFi.localIP());
  }
}
