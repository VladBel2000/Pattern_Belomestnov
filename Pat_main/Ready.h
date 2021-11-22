#pragma once
#include "Headers.h"

#ifndef Ready_h
#define Ready_h


#include "State.h"


class Ready : public State {
public:
    bool start(Navigator* navigator) override;
    bool stop(Navigator* navigator) override;
};


#endif //Ready_h