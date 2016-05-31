#include "Zone.h"
#pragma once
#include <fstream>

class List_Zones
{
public:
	List_Zones();
	~List_Zones();
	Zone *tmp_zone;
	deque<Zone> zones;
	bool add_Zone();
	bool delete_Zone();
	int * is_active();
	bool edit_Zone();
	bool read();
	bool save();
	void showAll();
	string showWhere(int a,int b, int c);
};

