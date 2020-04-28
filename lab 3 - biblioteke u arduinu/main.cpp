#include <Arduino.h>
#include "Sensors.h"

SENSORS sen;

void setup() {
  Serial.begin(9600);
  sen.DHT_init();
  sen.BH1750_init();
}

void loop() {
  sen.readTempHum();
  sen.readLight();
  freeRam();
}

int freeRam ()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}