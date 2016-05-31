#include "List_Zones.h"
#include <string>

List_Zones::List_Zones()
{
}


List_Zones::~List_Zones()
{
}
bool List_Zones::add_Zone()
{
    cout << "Dodaj strefe" << endl;
    cout << "Podaj nazwe:" << endl;
    string temp;
    cin >> temp;
    zones.push_back(Zone(zones.size(), temp));
    return true;
}

bool List_Zones::delete_Zone()
{
    if (zones.size() > 0)
    {
        cout << "Ktora strefe usunac?" << endl;
        for (size_t i = 0; i < zones.size(); i++)
        {
            cout << i << ". Nazwa: " << zones.at(i).show_name() << " ID:  " << zones.at(i).show_id() << endl;
        }
        int temp;
        cin >> temp;
        if (temp >= zones.size() || temp < 0)
        {
            cout << "Bledny wybor!" << endl;
            return false;
        }
        else
            zones.erase(zones.begin() + temp);
    }

    return false;
}

int* List_Zones::is_active()
{
    int temp[3] = { -1,-1,-1 };

    if (zones.size() > 0)
        for (size_t i = 0; i < zones.size(); i++)
        {
            if (zones.at(i).is_active() != temp)
            {
                temp[0] = i;
                temp[1] = zones.at(i).is_active()[0];
                temp[2] = zones.at(i).is_active()[1];
                return temp;
            }
        }
    return temp;
}
bool List_Zones::edit_Zone()
{
    if (zones.size() > 0)
    {
        cout << "Ktora strefe edytowac?" << endl;
        for (size_t i = 0; i < zones.size(); i++)
        {
            cout << i << ". Nazwa: " << zones.at(i).show_name() << " ID:  " << zones.at(i).show_id() << endl;
        }
        int temp;
        cin >> temp;
        if (temp >= zones.size() || temp < 0)
        {
            cout << "Bledny wybor!" << endl;
            return false;
        }
        else
        {
            string name;
            cout << "Edytuj Strefe:" << zones.at(temp).name<< endl;
            cout << "Podaj nazwe:" << endl;
            cin >> zones.at(temp).name;
            return true;

        }
    }
}

    bool List_Zones::read()
    {
        ifstream file;
        file.open("zones");
        if (!file.good())
            return false;
        string name;
        string active;
        int id,lvl;

        while (true) //petla nieskonczona
        {
            file >>lvl>> id >> name;
            if (file.good())
            {
                if (lvl == 0)
                {
                    zones.push_back(Zone(id, name));
                }
                else if (lvl == 1)
                {
                    zones.at(zones.size() - 1).objects.push_back(Object(id, name));
                }
                else if (lvl == 2)
                {
                    zones.at(zones.size() - 1).objects.at(zones.at(zones.size() - 1).objects.size() - 1).sensors.push_back(Sensor(id, name));
                }
            }
            else if(!file.fail())
            {
                std::cout << "Nie udalo sie wczytac stref" << std::endl;
                file.close();
                return false;
            }
            else
            {
                file.close();
                return false; //zakoncz wczytywanie danych - wystapil jakis blad (np. nie ma wiecej danych w fileu)
            }
        } //while
        file.close();
        return true;
    }

    bool List_Zones::save()
    {
        fstream file("zones", ios::out);
        if (file.good())
        {
            for (size_t i = 0; i <zones.size(); i++)
            {
                file <<"0 "<< zones.at(i).show_id() << " " << zones.at(i).show_name()<<endl;
                for (size_t j = 0; j < zones.at(i).objects.size(); j++)
                {
                    file << "1 " << zones.at(i).objects.at(j).show_id() << " " << zones.at(i).objects.at(j).show_name() << endl;
                    for (size_t k = 0; k < zones.at(i).objects.at(j).sensors.size(); k++)
                    {
                        file << "2 " << zones.at(i).objects.at(j).sensors.at(k).show_id() << " " << zones.at(i).objects.at(j).sensors.at(k).show_name() << endl;
                    }
                }
            }
            file.flush();
            file.close();
        }
        return true;
    }

    void List_Zones::showAll()
    {
        for (size_t i = 0; i <zones.size(); i++)
        {
            cout << "ID:" << zones.at(i).show_id() << " Nazwa: " << zones.at(i).show_name() << endl;
            for (size_t j = 0; j < zones.at(i).objects.size(); j++)
            {
                cout << " > ID:" << zones.at(i).objects.at(j).show_id() << " Nazwa: " << zones.at(i).objects.at(j).show_name() << endl;
                for (size_t k = 0; k < zones.at(i).objects.at(j).sensors.size(); k++)
                {
                    cout << " > > ID:" << zones.at(i).objects.at(j).sensors.at(k).show_id() << " Nazwa: " << zones.at(i).objects.at(j).sensors.at(k).show_name() << endl;
                }
            }
        }
    }

    string List_Zones::showWhere(int a,int b,int c)
    {
        string sh;
        if (a<zones.size() && a>-1)
            if (b<zones.at(a).objects.size() && b>-1)
                if (c<zones.at(a).objects.at(b).sensors.size() && c>-1)
                {
                    sh.append("ID: ");
                    //sh.append(to_string(zones.at(a).show_id()));
                    sh.append(" Nazwa: ");
                    sh.append(zones.at(a).show_name());
                    sh.append("\n");
                    sh.append(" > ID: ");
                    //sh.append(to_string(zones.at(a).objects.at(b).show_id()));
                    sh.append(" Nazwa: ");
                    sh.append(zones.at(a).objects.at(b).show_name());
                    sh.append("\n");
                    sh.append(" > > ID: ");
                    //sh.append(to_string(zones.at(a).objects.at(b).sensors.at(c).show_id()));
                    sh.append(" Nazwa: ");
                    sh.append(zones.at(a).objects.at(b).sensors.at(c).show_name());
                    sh.append("\n");
                }
                else sh.append("Brak\n");
            else sh.append("Brak\n");
        else sh.append("Brak\n");


        return sh;
    }
