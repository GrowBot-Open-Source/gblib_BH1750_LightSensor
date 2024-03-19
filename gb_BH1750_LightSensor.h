/*********************************************************************
 * gb_BH1750_LightSensor.h
 *
 * Copyright (C)    20124   [GrowBot Open Source],
 * GitHub Link :XXXXX
 * This Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Description:Implement DFRobot BH1750 Lightsensor into the growbot system
 *
 * Product Links：
 *
 * Sensor driver pin：I2C
 *
 * author  :  GrowBot
 * version :  V1.0
 * date    :  2024-05-14
 **********************************************************************/

#ifndef gb_BH1750_LightSensor_h
#define gb_BH1750_LightSensor_h

#include <Arduino.h>

class gb_BH1750_LightSensor
{
private:
    byte buff;
    int BH1750address;

public:
    gb_BH1750_LightSensor(int BH1750address, byte buff);

    // check if light is on or off
    bool isLightOn();

    // getLightIntensity
    int getLightIntensity();

    void BH1750_Init(int address);

    int BH1750_Read(int address);

    void BH1750_Setup();
};

#endif