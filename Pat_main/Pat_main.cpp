#pragma once
#include "Device.h"
#include "Real_Device.h"
#include "Speeds.h"
#include "Speed.h"
#include "Proxy_Device.h"
#include "Headers.h"

void test_delegate()
{
	printf("Test delegate:\n");

	Real_Device* dv1 = new Real_Device("Auto");
	dv1->get_rez();

	Real_Device* dv2 = new Real_Device("Walk");
	dv2->get_rez();

	Real_Device* dv3 = new Real_Device("Bicycle");
	dv3->get_rez();
}
void testProxy()
{ 
	Real_Device* dv1 = new Real_Device("Walk");
	printf("\nDevice: "); 
	dv1->get_rez(); 

	Proxy_Device* proxyDevice = new Proxy_Device();
	printf("Proxy device: "); 
	proxyDevice->get_rez();


	proxyDevice->initDevice(dv1); 
	printf("Device: ");
	dv1->get_rez(); 
	printf("Proxy device: ");
	proxyDevice->get_rez();
}
int main()
{
	testProxy();
}
