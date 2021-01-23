#include "Temperature.h"

void initTemp(){
  sensors.begin();
  for(int i = 0; i < 9; i++){
    sensors.setResolution(dallasSensorList[i], dallasResolution);
  }
}

void handleTemp(){
  unsigned long now = millis();
  if (now - lastDallas > dallasDelay) {
    sensors.requestTemperatures();
    for(int i = 0; i < dallasSensors; i++){
      float t = sensors.getTempC(dallasSensorList[i]);
      if(t > -50){
        publishMqtt(String(t).c_str(),dallasTopicList[i]);
      }
    }
    lastDallas = now;
  }
}
