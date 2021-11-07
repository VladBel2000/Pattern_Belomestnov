#pragma once
#include "Headers.h"
#include "Device.h"
#include "Real_Device.h"
#include "Speeds.h"
#include "Speed.h"
#include "Proxy_Device.h"
#include "Adapter.h"
#include "Special_walk.h"
#include "Decorator_device.h"
#include "Device_hard_Wrapper.h"
#include "Device_traffic_Wrapper.h"
#include "Component.h"
#include "Composite.h"
#include "User.h"
#include "Iterator_type_move.h"
#include "Iterator.h"
#include "Iterable_collection.h"
#include "Device_for_iter.h"



void test_adapter() 
{
	Special_Walk* human_1 = new Special_Walk();
	printf("Start special walk 1\n");
	human_1->start_special_Walk();

	printf("Start device_1 with special walk\n");
	Device* device_1 = new Adapter(human_1);
	human_1->start_special_Walk();
	printf("\n");

	Special_Walk* human_2 = new Special_Walk(1.5);
	printf("Start special walk 2\n");
	human_2->start_special_Walk();

	printf("Start device_2 with special walk\n");
	Device* device_2 = new Adapter(human_2);
	human_2->start_special_Walk();

	delete device_1;
	delete device_2;
	delete human_1;
	delete human_2;
}
void test_decorator()
{
	Device* dv1 = new Real_Device("Auto");
	dv1->get_rez();
	Device* dv2 = new Real_Device("Walk");
	dv2->get_rez();

	printf("\nCreate decorators for this device\n");
	Device* decorator1 = new Device_traffic_Wrapper(new Device_hard_Wrapper(dv1));
	decorator1->get_rez();
	Device* decorator2 = new Device_traffic_Wrapper(new Device_hard_Wrapper(dv2));
	decorator2->get_rez();

	delete dv1;
	delete dv2;
	delete decorator1;
	delete decorator2;
}
void test_composite() 
{
	printf("\nCreate first user\n");
	Component* user1 = new User("Vladislav", "2");
	printf("%s\n", user1->operation().c_str());

	printf("\nCreate user2 and user 3\n");
	Component* user2 = new User("Ivan", "1");
	Component* user3 = new User("Petr", "2");
	Component* list = new Composite;
	Component* group1 = new Composite;

	group1->add(user2);
	group1->add(user3);
	printf("%s \n", group1->operation().c_str());

	list->add(group1);
	list->add(user1);
	printf("%s\n", list->operation().c_str());

	Component* group2 = new Composite;
	group1->remove(user2);
	group2->add(user2);

	list->add(group2);
	printf("%s\n", list->operation().c_str());


	delete user1;
	delete user2;
	delete user3;
	delete list;
	delete group1;
}
void test_Iterator() 
{
	Speed* speed_1 = new Auto();
	Speed* speed_2 = new Walk();
	Speed* speed_3 = new Bicycle();

	Device_for_iter* dv1 = new Device_for_iter();
	// Letter* letter = new Letter();
	dv1->insert_type(speed_1);
	dv1->insert_type(speed_2);
	dv1->insert_type(speed_3);

	;
	Iterator<Speed*>* iter = dv1->createIterator();
	for (iter->first(); iter->havNext(); iter->next()) 
	{
		Speed* sp = iter->getCur();
		sp->get_rez();
		//printf("%d", sp->get_rez());
		//printf("%s", sp->get_rez().c_str());
	}
	delete speed_1;
	delete speed_2;
	delete speed_3;
	delete dv1;
}

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

