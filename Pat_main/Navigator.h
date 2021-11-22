#pragma once
#include "Headers.h"

#ifndef navigator_h
#define navigator_h

#include "State.h"

class State;

class Navigator{
private:
    State* state;
    list<string>* list_user;
    vector<int>* rez_of_work;
public:
    Navigator();
    void add_user(string p_user);
    list<string>* get_user();
    int get_rez();
    void changeStateTo(State* state1);
    void Is_working();
    int getResultsOfNavogator();
    void printCurrentState();
};
#endif //navigator_h