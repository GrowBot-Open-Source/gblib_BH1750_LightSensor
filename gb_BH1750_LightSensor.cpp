/*********************************************************************
 * gb_SD2405_RTCModule.cpp
 *
 * Copyright (C)    20124   [GrowBot Open Source],
 * GitHub Link :XXXXX
 * This Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Description:Implement DFRobot BH1750 light sensor into the growbot system
 *
 * Product Links：https://www.dfrobot.com/wiki/index.php/Gravity:_I2C_SD2405_RTC_Module_SKU:_DFR0469
 *
 * Sensor driver pin：I2C 0x23
 *
 * Connection:
 * VCC-5v
 * GND-GND
 * SCL-SCL(analog pin 5)
 * SDA-SDA(analog pin 4)
 * ADD-NC
 *
 * author  :  GrowBot
 * version :  V1.0
 * date    :  2024-05-14
 **********************************************************************/

#include "gb_BH1750_LightSensor.h"
#include <Arduino.h>
#include <Wire.h>

//********************************************************************************************
// Function Name: gb_BH1750_LightSensor()
// Function Declaration: create light sensor object
//********************************************************************************************
gb_BH1750_LightSensor::gb_BH1750_LightSensor(int BH1750address, byte buff)
{
    this->BH1750address = BH1750address;
    this->buff = buff;
}

//********************************************************************************************
// Function Name: BH1750_Init()
// Function Declaration: init light sensor
//********************************************************************************************
void gb_BH1750_LightSensor::BH1750_Init(int address)
{
    Wire.beginTransmission(address);
    Wire.write(0x10);
    Wire.endTransmission();
}

//********************************************************************************************
// Function Name: BH1750_Setup()
// Function Declaration: setup sensor
//********************************************************************************************
void gb_BH1750_LightSensor::BH1750_Setup()
{
    Wire.begin();
}

//********************************************************************************************
// Function Name: BH1750_Read()
// Function Declaration: readout sensor
//********************************************************************************************
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

//********************************************************************************************
// Function Name: isLightOn()
// Function Declaration: get status of light
//********************************************************************************************
bool gb_BH1750_LightSensor::isLightOn()
{
    if (getLightIntensity() >= 100)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//********************************************************************************************
// Function Name: getLightIntensity()
// Function Declaration: get light intensity of the light
//********************************************************************************************
int gb_BH1750_LightSensor::getLightIntensity()
{
    int i;
    uint16_t val = 0;
    BH1750_Init(BH1750address);
    delay(200);
    if (2 == BH1750_Read(BH1750address))
    {
        val = ((buff[0] << 8) | buff[1]) / 1.2;
        return (val, DEC);
        // Serial.print(val, DEC);
        // Serial.println("[lx]");
    }
    delay(150);
}