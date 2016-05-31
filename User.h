#pragma once
#include <string>
using namespace std;
class User
{
public:
	string name,password, access;
	int id;

	User(int id_, string nazwa, string ac, string pass);
	bool set_name(string nazwa);
	int show_id();
	string show_name();
	~User();
};

