#include "Debug.h"

void initDebug(){
  if(debug){
    Serial.begin(115200);
  }
}

template <class T>
T writeDebug (T a) {
  if(debug){
    Serial.println(a);
  }
}
