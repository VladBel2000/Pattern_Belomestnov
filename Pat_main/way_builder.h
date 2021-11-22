#pragma once
#include "Headers.h"

#ifndef way_builder_h
#define way_builder_h


#include <list>
#include "Way.h"
#include "builder.h"

class Way_builder : public Builder<Way*> {
private:
    Way* way;
    void builder() override 
    { 
        way = new Way(); 
    }
public:
    Way_builder()
    {
        this->builder();
    }
    ~Way_builder()
    { 
        delete way; 
    }
    void time(int p_time) 
    { 
        way->setTime(p_time);
    }
    void list_number_node(list<int>* p_node)
    {
        for (int p_node : *p_node)
            way->addNode(p_node);
    }
    void length(int p_length) 
    { 
        way->setLength(p_length);
    }
    Way* build() override {
        return way;
    }

};


#endif //way_builder_h