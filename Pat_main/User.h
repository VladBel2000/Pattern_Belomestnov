#pragma once
#include "Headers.h"
#include "Component.h"

#ifndef user_h
#define user_h

#include "Component.h"

class User : public Component 
{
private:
    string login;
    string prior;
public:
    User(string p_login, string p_prior)
    {
        this->login = p_login;
        this->prior = p_prior;
    }
    string operation() override 
    {
        return "[User - login = " + login + ", prior = " + prior + "]";
    }
};


#endif //user_h