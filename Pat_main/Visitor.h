#pragma once
#include "Headers.h"

#ifndef visitor_h
#define visitor_h


#include "Navigator.h"

class Navigator;

class Visitor {
public:
    virtual std::string visit(Navigator* navigator) = 0;
};


#endif //visitor_h