#pragma once
#include "Headers.h"

#ifndef Vicible_collection
#define Vicible_collection

#include "Visitor.h"

class Vicible_collection {
public:
    virtual std::string accept(Visitor* visitor) = 0;
};


#endif //Vicible_collection