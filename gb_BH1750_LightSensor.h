#ifndef gb_BH1750_LightSensor.h
#define gb_BH1750_LightSensor.h

#include <Arduino.h>

class gb_BH1750_LightSensor {
    private:
        byte buff;
        int BH1750address;
        void BH1750_Init;
        int BH1750_Read;
        int BH1750_Setup;    
    public:
        gb_BH1750_LightSensor(BH1750address, buff);
        bool isLightOn();
        int getLightIntesity();
};

#endif