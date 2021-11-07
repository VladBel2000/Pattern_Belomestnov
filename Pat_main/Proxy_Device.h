#pragma once
#ifndef Proxy_Device_h
#define Proxy_Device_h

#include "Device.h"
#include "Real_Device.h"

class Proxy_Device : public Device
{
private:
	Real_Device* device;
	void log()
	{
		printf("\n[ProxyLog]\tResult: ");
	}
public:
	Proxy_Device()
	{
		device = new Real_Device();
	}
	void initDevice(Real_Device* p_device)
	{
		if (device != NULL)
			delete device;
		device = p_device;
	}
	virtual int get_rez() override
	{
		log();
		return device->get_rez();
	}
};
#endif // !Proxy_Device_h

