#pragma once
#include "Headers.h"

#ifndef visitor_h
#define visitor_h


#include "Way.h"

class Way;

class Visitor {
public:
    virtual string visit(Way* way) = 0;
};


#endif //visitor_h