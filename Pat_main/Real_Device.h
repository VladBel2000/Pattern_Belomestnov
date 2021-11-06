#pragma once
#ifndef Real_Device_h
#include "Device.h"
#include "Speeds.h"
#include "Headers.h"

class Real_Device : public Device
{
private:
	string type_Device;
public:
	Real_Device()
	{
		type_Device = "default";
		printf("Initiate type: %s\n", type_Device.c_str());
		speed = new Auto();
	}
	Real_Device(string p_init)
	{
		type_Device = p_init;
		printf("Initiate type: %s\n", type_Device.c_str());
		if (strcmp(p_init.c_str(), (const char*)("Auto")) == 0)
			speed = new Auto();
		else if (strcmp(p_init.c_str(), (const char*)("Walk")) == 0)
			speed = new Walk();
		else if (strcmp(p_init.c_str(), (const char*)("Bicycle")) == 0)
			speed = new Bicycle();
	}
	void set_speed(string p_setter)
	{
		type_Device = p_setter;
	}
	int get_rez() override
	{
		return speed->get_rez();
	}
};
#endif // !Real_Device_h