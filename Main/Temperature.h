#pragma once

#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>


OneWire oneWire(4);
DallasTemperature sensors(&oneWire);

const uint8_t* dallasSensorList[30];
const char* dallasTopicList[30];
int dallasSensors = 0;

unsigned long lastDallas = 0;
