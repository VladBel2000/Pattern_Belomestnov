#pragma once
#include "Headers.h"

#ifndef Device_hard_Wrapper_h
#define Device_hard_Wrapper_h

#include "Decorator_device.h"
#include <list>

class Device_hard_Wrapper : public Decorator_device 
{
private:
    int hard;
public:
    Device_hard_Wrapper(Device* device) : Decorator_device(device) 
    {
        hard = 0;
    }
    int get_rez() override 
    {
        hard = Decorator_device::get_rez() * 5;
        printf("Device_hard_Wrapper: hard = %d\n", hard);
        return hard;
    }
};

#endif //Device_hard_Wrapper_h