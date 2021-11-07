#pragma once
#include "Speed.h"
class Device
{
protected: Speed* speed;
public:
	Device() {}
	~Device() {}

	virtual int get_rez()
	{
		return speed->get_rez();
	}
};