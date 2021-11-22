#pragma once
#include "Headers.h"

#ifndef Way_h
#define Way_h

#include "Clonable_collection.h"


using namespace std;

class Way : public Clonable_Collection {
private:
    list<int>* list_number_node;
    int length;
    int time;
public:
    Way() 
    {
        list_number_node = new list<int>();
        length = 0;
        time = 0;
    }
    Way(Way& p_way) 
    {
        length = p_way.length;
        time = p_way.time;
        list_number_node = new list<int>();
        *list_number_node = *(p_way.list_number_node);
    }

    void addNode(int p_number) 
    {
        if (list_number_node == NULL)
            list_number_node = new list<int>();
        list_number_node->push_back(p_number);
    }
    void setTime(int p_time)
    { 
        time = p_time;
    }
    void setLength(int p_length)
    {
        length = p_length;
    }

    string toString() 
    {
        string listNumb = "";
        for (int digit : *list_number_node)
            listNumb += to_string(digit)+ " ";
        return "Way\n[\n\tlist_node = " + listNumb + "\n\ttime = " + to_string(time) + "\n\tlength = " + to_string(length) + "\n]\n";
    }

    Way* clone() override { return new Way(*this); }

    const int& getTime() const { return time; }

    list<int>* get_list_number_node() const { return list_number_node; }

    const int& get_length() const { return length; }

};

#endif //Way_h

