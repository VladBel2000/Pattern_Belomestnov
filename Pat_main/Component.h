#pragma once
#include "Headers.h"

#ifndef component_h
#define component_h

#include <string>

class Component {
public:
    virtual ~Component() {}
    virtual void add(Component* component) {}
    virtual void remove(Component* component) {}
    virtual bool isComposite() 
    { 
        return false; 
    }
    virtual string operation() = 0;
};
#endif //component_h
