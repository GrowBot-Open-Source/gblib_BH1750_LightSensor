#include <gb_BH1750_LightSensor.h>

gb_BH1750_LightSensor light(0x23, [2]); // BH1750 address = ; buff =

void setup()
{
    light.BH1750_Setup();
}

void loop()
{
    light.isLightOn();
    light.getLightIntensity();
}