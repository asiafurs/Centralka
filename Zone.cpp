#include "Zone.h"
#include <iostream>

Zone::Zone(int id_, string nazwa)
{
	name = nazwa;
	id = id_;
}

bool Zone::set_name(string nazwa)
{
	name = nazwa;
	return true;
}

bool Zone::add_Object()
{
	cout << "Dodaj obiekt" << endl;
	cout << "Podaj nazwe:" << endl;
	string temp;
	cin >> temp;
	objects.push_back(Object(objects.size(), temp));
	return true;
}

bool Zone::delete_Object()
{
	if (objects.size() > 0)
	{
		cout << "Ktory obiekt usunac?" << endl;
		for (size_t i = 0; i < objects.size(); i++)
		{
			cout << i << ". Nazwa: " << objects.at(i).show_name() << " ID:  " << objects.at(i).show_id() << endl;
		}
		int temp;
		cin >> temp;
		objects.erase(objects.begin() + temp);
	}

	return false;
}

int* Zone::is_active()
{
	int temp[2] = { -1,-1 };

	if (objects.size() > 0)
		for (size_t i = 0; i < objects.size(); i++)
		{
			if (temp[1] = objects.at(i).is_active()>(-1))
			{
				temp[0] = i;
				return temp;
			}
		}
	return temp;
}

int Zone::show_id()
{
	return id;
}

string Zone::show_name()
{
	return name;
}


Zone::~Zone()
{
}
