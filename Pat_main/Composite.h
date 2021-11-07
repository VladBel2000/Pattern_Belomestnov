#pragma once
#include "Headers.h"


#ifndef Composite_h
#define Composite_h

#include <list>
#include "Component.h"

class Composite : public Component {
protected:
    list<Component*> child;
public:
    void add(Component* component) override 
    {
        this->child.push_back(component);
    }
    void remove(Component* component) override 
    {
        child.remove(component);
    }
    bool isComposite() override 
    { 
        return true; 
    }
    string operation() override {
        std::string result = "";
        for (Component* c : child) {
            if (c == child.back())
                result += c->operation();
            else
                result += c->operation() + "+";
        }
        return "Group(" + result + ")";
    }
};

#endif //Composite_h