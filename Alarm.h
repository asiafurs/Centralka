#pragma once
#include "List_Zones.h"
#include "List_users.h"
#include <time.h>

class Alarm:List_users
{
public:
	Alarm();
	~Alarm();
	int login();
	int menu();
	int check();
private:
	int temp[3] = { -1,-1,-1 };
	string user;
	string acc;
	List_users *list_users;
	List_Zones *list_zones;
	void save_Raports(string save);
	string read_Raports();
};

