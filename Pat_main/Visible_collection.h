#pragma once
#include "Headers.h"

#ifndef Vicible_collection_h
#define Vicible_collection_h

#include "Visitor.h"

class Vicible_collection {
public:
    virtual string accept(Visitor* visitor) = 0;
};


#endif //Vicible_collection