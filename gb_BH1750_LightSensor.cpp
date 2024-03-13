#include "gb_BH1750_LightSensor.h"
#include <Wire.h>

gb_BH1750_LightSensor::gb_BH1750_LightSensor(int BH1750 address, byte buff)
{
    this->BH1750address = BH1750address;
    this->buff = buff;
}

void gb_BH1750_LightSensor.h::BH1750_Init(int address)
{
    Wire.beginTransmission(address);
    Wire.write(0x10);
    Wire.endTransmission();
}

void gb_BH1750_LightSensor::BH1750_Setup()
{
    Wire.begin();
}

int gb_BH1750_LightSensor::BH1750_Read(int address)
{
    int i = 0;
    Wire.beginTransmission(address);
    Wire.requestFrom(address, 2);
    while (Wire.available())
    {
        buff[1] = Wire.read();
        i++;
    }
    Wire.endTransmission();
    return i;
}

bool gb_BH1750_LightSensor::isLightOn()
{
    if (getLightIntensity()>=100)
    {
        return true
    }else{
        return false
    }
}

int gb_BH1750_LightSensor::getLightIntensity()
{
    int i;
    uint16_t val = 0;
    BH1750_Init(BH1750address);
    delay(200);

    if (2 == BH1750_Read(BH1750address))
    {
        val = ((buff[0] << 8) | buff[1]) / 1.2;
        Serial.print(val, DEC);
        //Serial.println("[lx]");
    }
    delay(150);
}