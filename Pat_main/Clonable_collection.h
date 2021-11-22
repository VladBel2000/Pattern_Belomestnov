#pragma once
#ifndef clonable_collection_h
#define clonable_collection_h

class Clonable_Collection {
public:
    virtual Clonable_Collection* clone() = 0;
};


#endif //clonable_collection_h