#pragma once

#ifndef Iterator_type_move_H
#define Iterator_type_move_H

#include <vector>
#include "Speed.h"
#include "Real_device.h"

class Iterator_type_move : public Iterator<Speed*>
{
private:
    vector<Speed*>* collection;
    int cur = 0;
public:
    Iterator_type_move(vector<Speed*>* list) 
    { 
        cur = 0;
        collection = list; 
    }
    ~Iterator_type_move() {}
    void first() override 
    {
        cur = 0;
    }
    bool havNext() override 
    {
        return cur < collection->size();
    }
    void next() override 
    {
        if (this->havNext())
            cur++;
    }
    Speed*& getCur() override 
    {
        return collection->at(cur);
    }
};

#endif //Iterator_type_move_H