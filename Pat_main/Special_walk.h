#pragma once
#include "Headers.h"
#ifndef Special_walk_h
#define Special_walk_h

#include <cstring>

class Special_Walk 
{
private:
    float speed, koef_power;

public:
    Special_Walk() 
    {
        speed = 1;
        koef_power = 1;
    }
    Special_Walk(float p_koef_power)
    {
        koef_power = p_koef_power;
        speed = rand() % 5 + 1;
    }
    Special_Walk(Special_Walk* help)
    { 
        koef_power = help->koef_power;
        speed = help->speed;
    }
    ~Special_Walk() {}

    float get_koef_power() 
    { 
        return koef_power;
    }
    float get_speed()
    {
        return koef_power * speed;
    }
    void set_Power(float p_koef_power)
    {
        koef_power = p_koef_power;
    }
    void start_special_Walk()
    {
        printf("Specail walk was created:\nspeed = %f,\tkoef_power - %f\n", get_speed(), get_koef_power());
        printf("Created is successful!\n");
    }
};
#endif //Special_walk_h