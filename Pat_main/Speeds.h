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
		int speed = rand() % 20 + 30;
		printf("Auto speed running\n");
		return speed;
	}
};

class Walk : public Speed
{
public:
	int get_rez() override
	{
		int speed = rand() % 5 + 10;
		printf("Walk speed running\n");
		return speed;
	}
};

class Bicycle : public Speed
{
public:
	int get_rez() override
	{
		int speed = rand() % 10 + 20;
		printf("Bicycle speed running\n");
		return speed;
	}

};
#endif // !Speeds_h