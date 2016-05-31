#include "Object.h"

Object::Object(int id_, string nazwa)
{
	name = nazwa;
	id = id_;
}

bool Object::set_name(string nazwa)
{
	name = nazwa;
	return true;
}

bool Object::add_sensor()
{
	cout << "Dodaj czujnik"<<endl;
	cout << "Podaj nazwe:" << endl;
	string temp;
	cin >> temp;
	int a = sensors.size();
	sensors.push_back(Sensor(a, temp));
	return true;
}

bool Object::delete_sensor()
{
	if (sensors.size() > 0)
	{
		cout << "Ktory czujnik usunac?" << endl;
		for (size_t i = 0; i < sensors.size(); i++)
		{
			cout << i <<". Nazwa: " << sensors.at(i).show_name() << " ID:  " << sensors.at(i).show_id()<<endl;
		}
		int temp;
		cin >> temp;
		sensors.erase(sensors.begin()+temp);
	}

	return false;
}

int Object::is_active()
{
	if (sensors.size() > 0)
		for (size_t i = 0; i < sensors.size(); i++)
		{
			if (sensors.at(i).is_active() == true)
				return i;
		}
	return -1;
}

int Object::show_id()
{
	return id;
}

string Object::show_name()
{
	return name;
}


Object::~Object()
{
}
