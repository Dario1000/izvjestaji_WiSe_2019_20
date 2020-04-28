#include "Sensors.h"
#include <LowPower.h>

SENSORS sensor;

void setup() {
  Serial.begin(9600);
  sensor.DHT_init();
  sensor.BH1750_init();
}

void loop() {
  sensor.readTempHum();
  sensor.readLight();

  delay(100);
  for(uint8_t i = 0; i < 8; i++)
  {
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  }
  delay(100);
}
