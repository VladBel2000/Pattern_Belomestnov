#pragma once
#include "Headers.h"

#ifndef state_h
#define state_h

#include "Navigator.h"
class Navigator;

class State {
public:
    virtual bool start(Navigator* navigator) = 0;
    virtual bool stop(Navigator* navigator) = 0;
};

#endif //state_h