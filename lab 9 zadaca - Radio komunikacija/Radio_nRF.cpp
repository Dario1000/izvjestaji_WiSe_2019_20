#include "Radio_nRF.h"
#include "main.h"

RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

RADIO::RADIO() {}
RADIO::~RADIO() {}

const byte address[6] = {"3node"};

void RADIO::nRF_init()
{
    radio.begin();
    radio.setDataRate(RF24_250KBPS);
    radio.setChannel(111);
    radio.setPALevel(RF24_PA_MAX);
    radio.setRetries(3, 5); // delay, count
    radio.openWritingPipe(address);
}

bool RADIO::RF_send(struct SensorData sensorData)
{
    bool rslt;
    
    rslt = radio.write(&sensorData, sizeof(sensorData));
    // Always use sizeof() as it gives the size as the number of bytes.
    // For example if dataToSend was an int sizeof() would correctly return 2

    Serial.print("Data Sent ");
    Serial.print(sensorData.temp);
    Serial.print(" ");
    Serial.print(sensorData.lightLevel);

    return (rslt);
}

void RADIO::RF_receive(bool rslt)
{
    if(rslt){
        Serial.println("Slanje uspjesno!");
    }
    else{
        Serial.println("Slanje nije uspjesno");
    }
    
}