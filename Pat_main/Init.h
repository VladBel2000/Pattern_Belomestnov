#pragma once
#include "Headers.h"

#ifndef Init_h
#define Init_h


#include "State.h"

class Init : public State {
public:
    bool start(Navigator* navigator) override;
    bool stop(Navigator* navigator) override;
};


#endif //Init_h