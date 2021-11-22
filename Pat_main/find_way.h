#pragma once
#include "Headers.h"

#ifndef find_way_h
#define find_way_h

#include "Builder.h"
#include "Way.h"
#include "way_builder.h"


class find_way {
private:
    find_way() {}
    find_way(const find_way&);
    find_way& operator = (find_way&);
public:
    ~find_way() {}
    static find_way& getInstance() 
    {
        static find_way instance;
        cout << "Return a instance of find_way" << endl;
        return instance;
    }

    Way* make_need_way() 
    {
        Way_builder* way_builder = new Way_builder();
        way_builder->length(40);
        way_builder->list_number_node(new list<int>{ 4, 6, 1, 0 });
        return way_builder->build();
    }

    Way* make_all_way() 
    {
        Way_builder* way_builder = new Way_builder();
        way_builder->length(30);
        way_builder->time(10);
        way_builder->list_number_node(new list<int>{ 5, 10, 20, 100, 15 });
        return way_builder->build();
    }
};


#endif //find_way_h