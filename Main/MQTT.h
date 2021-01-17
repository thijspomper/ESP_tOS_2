#pragma once

#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

#define MSG_SIZE (50)
char msg[MSG_SIZE];
