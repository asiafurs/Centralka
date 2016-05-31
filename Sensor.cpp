#include "Sensor.h"

bool Sensor::set_name(string nazwa)
{
	name = nazwa;
	return true;
}

bool Sensor::is_active()
{
	return ((activ == true) ? true : false);
}

int Sensor::show_id()
{
	return id;
}

string Sensor::show_name()
{
	return name;
}



