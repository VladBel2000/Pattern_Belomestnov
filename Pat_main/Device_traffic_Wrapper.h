#pragma once
#include "Headers.h"

#ifndef Device_traffic_Wrapper_h
#define Device_traffic_Wrapper_h


#include "Decorator_device.h"

class Device_traffic_Wrapper : public Decorator_device 
{
private:
    int traffic;
public:
    Device_traffic_Wrapper(Device* device) : Decorator_device(device)
    {
        traffic = 0;
    }
    int get_rez() override 
    {
        int rez = Decorator_device::get_rez();
        traffic = rez / 10;
        printf("Device_traffic_Wrapper: traffic = %d\n", traffic);
        return traffic;
    }
};


#endif //Device_traffic_Wrapper_h