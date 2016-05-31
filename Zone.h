#include "Object.h"
#pragma once
class Zone
{
public:

	Zone(int id_, string nazwa="Bez nazwy");
	bool set_name(string nazwa);
	bool add_Object();
	bool delete_Object();
	int* is_active();
	int show_id();
	string show_name();
	~Zone();
	deque<Object> objects;
	string name;
	int id;
};

