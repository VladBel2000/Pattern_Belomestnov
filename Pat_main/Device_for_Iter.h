#pragma once
#ifndef Device_for_iter
#include "Device.h"
#include "Speeds.h"
#include "Speed.h"
#include "Headers.h"
#include "Iterable_collection.h"

class Device_for_iter : public Iterable_Collection
{
private:
	vector <Speed*>* type_move;
public:
	Device_for_iter()
	{
		type_move = new vector<Speed*>();
	}
	void insert_type(Speed* speed1)
	{
		type_move->push_back(speed1);
	}
	Iterator<Speed*>* createIterator() override 
	{
		return new Iterator_type_move(type_move);
	}
};
#endif // !Device_for_iter