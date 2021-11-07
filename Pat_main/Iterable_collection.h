#pragma once
#include "Headers.h"

#ifndef itereble_collection_h
#define itereble_collection_h

#include "Iterator.h"
#include "Speed.h"

class Iterable_Collection 
{
public:
    virtual Iterator<Speed*>* createIterator() = 0;
};


#endif //itereble_collection_h