#include "Sensors.h"
#include <LowPower.h>

SENSORS sensor;

typedef enum {
  READ_SERIAL,
  READ_SENSORS,
  SLEEP_STATE,
  RADIO_COMM,
  NUM_STATES
} StateType;

StateType state = READ_SERIAL;
/*
READ_SERIAL
READ_SENSOR
RADIO_COMM
SLEEP_STATE
*/

void blink(){
    
}

void setup()
{
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), blink, RISING);
  sensor.DHT_init();
  sensor.BH1750_init();
}

void loop()
{
  switch(state){
    case READ_SERIAL:
      Serial.println("Read Serial");

      state = READ_SENSORS;
      break;

    case RADIO_COMM:
      //Kod za radio komunikaciju
	  
      state = SLEEP_STATE;
      break;

    case READ_SENSORS:
      sensor.readTempHum();
      sensor.readLight();

        state = RADIO_COMM;
        break;
      
    case SLEEP_STATE:
        delay(50);
        LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
        delay(50);

        state = READ_SERIAL;
        break;
  }
}
