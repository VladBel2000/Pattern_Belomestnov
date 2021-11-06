#pragma once
#include "Headers.h"
#ifndef Special_walk_h
#define Special_walk_h

#include <cstring>

class Special_Walk {
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

    int get_koef_power() 
    { 
        return koef_power;
    }
    int get_speed()
    {
        return koef_power * speed;
    }
    void set_Power(float p_koef_power)
    {
        koef_power = p_koef_power;
    }
};
#endif //Special_walk_h