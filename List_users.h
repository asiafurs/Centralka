#include "User.h"
#pragma once
#include <deque>
#include <iostream>
#include <fstream>

class List_users
{
public:
	List_users();
	~List_users();
	bool add_User();
	bool edit_User();
	bool delete_User();
	bool search(string login, string pass);
	bool read();
	bool save();
	deque<User> users;

};

