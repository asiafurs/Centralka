#include "User.h"

User::User(int id_, string nazwa = "admin", string ac = "admin", string pass="admin")
{
	name = nazwa;
	id = id_;
	access = ac;
	password = pass;
}

bool User::set_name(string nazwa)
{
	name = nazwa;
	return true;
}

int User::show_id()
{
	return id;
}

string User::show_name()
{
	return name;
}

User::~User()
{
}
