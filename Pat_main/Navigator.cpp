#pragma once
#include "Headers.h"


#include "Navigator.h"
#include "Init.h"

class State;

Navigator::Navigator()
    {
        list_user = new list<string>();
        state = new Init();
        state->stop(this);
        rez_of_work = new std::vector<int>();
    }
void Navigator:: add_user(string p_user)
    {
        if (list_user == NULL)
            list_user = new list<string>();
        list_user->push_back(p_user);
    }
list<string>* Navigator:: get_user()
    {
        return list_user;
    }
int Navigator:: get_rez()
    {
        return rand() % 1;
    }
void Navigator:: changeStateTo(State* state1)
    {
        cout << "Change state to " << typeid(*state1).name() << std::endl;
        if (this->state != nullptr)
            delete this->state;
        this->state = state1;
    }

void Navigator:: Is_working()
    {
        int result = this->get_rez();
        rez_of_work->push_back(result);
    }

int Navigator:: getResultsOfNavogator()
    {
        if (!state->start(this))
        {
            cout << "Could not run a navogator - it is already running" << std::endl;
            return -1;
        }
        else
        {
            this->Is_working();
            state->stop(this);
            return rez_of_work->back();
        }
    }
void Navigator:: printCurrentState()
    {
        std::cout << "Current state is " << typeid(*state).name() << std::endl;
    }