#include <string>
#pragma once
using namespace std;
class Sensor
{
public:
	Sensor(int id_, string nazwa) { id = id_; name = nazwa; activ = false; }
	~Sensor() {}
	bool set_name(string nazwa);
	bool is_active();
	int show_id();
	string show_name();
	bool activ;
	string name;
	int id;
};

