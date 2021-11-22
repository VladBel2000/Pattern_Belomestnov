#pragma once
#include "Headers.h"

#ifndef Is_working_h
#define Is_working_h


#include "State.h"


class Is_working : public State {
public:
    bool start(Navigator* navigator) override;
    bool stop(Navigator* navigator) override;
};


#endif //Ready_h