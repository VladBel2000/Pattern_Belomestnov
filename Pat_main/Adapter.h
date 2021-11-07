#pragma once
#include "Headers.h"
#ifndef Adapter_h
#define Adapter_h

#include "Special_walk.h"
#include "Device.h"

class Adapter : public Device 
{
private:
    Special_Walk* adaptable;
    int initSpecial() 
    {
        printf("Koef of power = %f \n", adaptable->get_koef_power());
        printf("Speed = %f \n", adaptable->get_speed());
        printf("Special walk is successful\n");
        return(adaptable->get_speed());
    }
public:
    Adapter() 
    { 
        adaptable = new Special_Walk();
    }
    Adapter(Special_Walk* help) 
    { 
        adaptable = help; 
    }
    ~Adapter() 
    { 
        delete adaptable; 
    }

    int get_rez() override 
    {
        return this->initSpecial();
    }

};

#endif //Adapter_h