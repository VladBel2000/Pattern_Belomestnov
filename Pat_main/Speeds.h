#pragma once
#ifndef Speeds_h
#define Speeds_h
#include <cstdio>
#include "Speed.h"
#include "Headers.h"


class Auto : public Speed
{
public:
	int get_rez() override
	{
		printf("Auto rez - running\n");
		return(rand() % 20 + 30);
	}
};

class Walk : public Speed
{
public:
	int get_rez() override
	{
		printf("Walk rez - running\n");
		return(rand() % 5 + 10);
	}
};

class Bicycle : public Speed
{
public:
	int get_rez() override
	{
		printf("Bicycle rez - running\n");
		return(rand() % 10 + 20);
	}

};
#endif // !Speeds_h