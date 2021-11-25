#pragma once
#include "Headers.h"

#ifndef Write_users_H
#define Write_users_H

#include "Visitor.h"

template<typename Base, typename T>
inline bool instanceof(const T* ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

class Write_users : public Visitor {
public:
    string visit(Way* way) override
    {
        string result = "";
        list<int>* list_node = way->get_list_number_node();
        result += "\"List of node\":[";
        for (auto str : *list_node) {
            result += "\"" + to_string(str) + "\",";
        }
        result.pop_back(); result += "]";
        return result;
    }

};


#endif //Write_users_H