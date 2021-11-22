#pragma once
#include "Headers.h"

#ifndef builder_h
#define builder_h

template <class T>
class Builder {
public:
    Builder() {}
    ~Builder() {}
    virtual void builder() = 0;
    virtual T build() = 0;
};


#endif //#define builder_h
