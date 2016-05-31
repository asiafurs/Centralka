#include "Sensor.h"
#pragma once
#include <deque>
#include <iostream>

class Object
{
public:
	Object(int id_, string nazwa="Bez nazwy");
	~Object();
	bool set_name(string nazwa);
	bool add_sensor();
	bool delete_sensor();
	int is_active();
	int show_id();
	string show_name();
	deque<Sensor> sensors;
	string name;
	int id;

};

