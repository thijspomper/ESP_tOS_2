#include "Wifi.h"

void initWifi(){
  if(wifi){
    WiFi.mode(WIFI_STA);
    WiFi.hostname(deviceName);
    WiFi.begin(wifiSSID, wifiPass);
    writeDebug("Connecting...");
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
      writeDebug("Connection Failed! Rebooting...");
      delay(5000);
      ESP.restart();
    }
    writeDebug("Connected");
    writeDebug(WiFi.localIP());
  }
}
