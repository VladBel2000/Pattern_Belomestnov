#pragma once
#include "Headers.h"

#ifndef Decorator_device_h
#define Decorator_device_h

#include "Device.h"


class Decorator_device : public Device 
{
protected:
    Device* device;
public:
    Decorator_device(Device* dl) : device(dl) {}
    int get_rez() override 
    {
        return device->get_rez();
    }

};

#endif //Decorator_device_h