#pragma once
#include "Headers.h"

#ifndef iterator_h
#define iterator_h

template <class T>
class Iterator 
{
    friend class Iterable_Collection;
public:
    virtual void next() = 0;
    virtual void first() = 0;
    virtual bool havNext() = 0;
    virtual T& getCur() = 0;
};

#endif //iterator_h