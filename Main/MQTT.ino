#include "MQTT.h"

void initMqtt(){
  client.setServer(mqttServer, 1883);
  handleMqtt();
}

void handleMqtt(){
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

void publishMqtt(const char* message, const char* topic){
  client.publish(topic, message);
}

void reconnect(){
  while (!client.connected()) {
    writeDebug("[MQTT]: Establishing connection");
    String clientId = deviceName;
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str(), mqttUser, mqttPass)) {
      writeDebug("[MQTT]: Connected");
    } else {
      writeDebug("[MQTT]: Connection failed, waiting 5 seconds");
      delay(5000);
    }
  }
}
