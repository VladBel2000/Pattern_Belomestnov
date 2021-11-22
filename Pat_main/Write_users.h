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
    string visit(Navigator* navigator) override 
    {
        string result = "";
        list<string>* list_user = navigator->get_user();
        result += "\"List of users\":[";
        for (auto now_user : *list_user) {
            result += "\"" + now_user + "\",";
        }
        result.pop_back(); result += "],";
        return result;
    }

};


#endif //Write_users_H