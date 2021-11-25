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
#include "Way.h"
#include "builder.h"
#include "way_builder.h"
#include "find_way.h"
//#include "Clonable_Collection.h"
#include "Navigator.h"


#include "State.h"
#include "Init.h"
#include "Ready.h"
#include "Is_working.h"
#include "Write_users.h"
//#include "Visible_collection.h"





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
	dv1->insert_type(speed_1);
	dv1->insert_type(speed_2);
	dv1->insert_type(speed_3);

	;
	Iterator<Speed*>* iter = dv1->createIterator();
	for (iter->first(); iter->havNext(); iter->next()) 
	{
		Speed* sp = iter->getCur();
		sp->get_rez();
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
void testBuilder() 
{
	list<int>* list_number_node = new list<int>();
	list_number_node->push_back(3);
	list_number_node->push_back(100);
	list_number_node->push_back(5);

	cout << "Build way from builder:" << endl;
	Way_builder* builder = new Way_builder();
	builder->time(17);
	builder->length(35);
	builder->list_number_node(list_number_node);
	Way* exampleWay = builder->build();
	cout << exampleWay->toString();

	cout << endl << "Build way from find_way:" << endl;
	find_way& f_way = find_way::getInstance();
	Way* way1 = f_way.make_need_way();
	cout << way1->toString() << endl;

	Way* way2 = f_way.make_all_way();
	cout << way2->toString() << endl;

	delete list_number_node;
	delete builder;
	delete way1;
	delete way2;
}

void testPrototype() 
{
	cout << "Make a empty way: \n";
	Way* way_1 = new Way();
	cout << way_1->toString();

	cout << "Clone this way" << endl;
	Way* way_1_1 = way_1->clone();
	cout << way_1_1->toString();

	cout << "Set time in way_1" << endl;
	way_1->setTime(49);
	cout << "1) " << way_1->toString();
	cout << "2) " << way_1_1->toString();

	delete way_1;
	delete way_1_1;
}
void testStates() 
{
	cout << "Create a Navigator and get result from him" << endl << endl;
	Navigator* navig1 = new Navigator();
	navig1->printCurrentState();
	int result = navig1->getResultsOfNavogator();

	cout << endl << "Now change state to Is_working and try navigator to work" << endl;
	navig1->changeStateTo(new Is_working);
	result = navig1->getResultsOfNavogator();
	
}

void testStrategy() 
{
    cout << "Create speed based on auto:\n";
	Speed* speed_1 = new Auto();
    cout << speed_1->get_rez() << "\tCar" << endl;

    cout << "Now change speed which based on the Walk:" << endl;
	speed_1 = new Walk();
    cout << speed_1->get_rez() << "\tWalk" << endl;
	}

void testVisitor() {
    cout << "Get a default way and add some nodes" << endl;
    find_way& find_w = find_way::getInstance();
    Way* way = find_w.make_need_way();
	way->addNode(6);
	way->addNode(15);
	way->addNode(17);
    Visitor* visitor = new Write_users();
    string str = visitor->visit(way);
    cout << "Our nodes: " << str << endl;
}
