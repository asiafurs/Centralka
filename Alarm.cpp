#include "Alarm.h"
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <windows.h>


Alarm::Alarm()
{
    user = "";
    acc = "";
    list_users = new List_users;
    list_zones = new List_Zones;
    list_zones->read();
    list_users->read();

}

Alarm::~Alarm()
{
}
int Alarm::login()
{
    cout << "Logowanie do alarmu" << endl;
    cout << "Wybierz operacje:" << endl;
    cout << "1. Zaloguj" << endl;
    cout << "2. Anuluj" << endl;
    int select = -1;
    string username;
    string pass;
    cin >> select;
    switch (select)
    {
    case 1:
        cout << "Wprowadz login:" << endl;
        cin >> username;
        cout << "Wprowadz haslo" << endl;
        cin >> pass;
        if (list_users->users.size() > 0)
        {
            for (size_t i = 0; i < list_users->users.size(); i++)
            {
                if (list_users->users.at(i).show_name() == username && list_users->users.at(i).password == pass)
                {
                    cout << "Zalogowany jako: " << username << endl;
                    cout << "Numer dostepu: " << list_users->users.at(i).access << endl;
                    system("pause");
                    user = username;
                    acc=list_users->users.at(i).access;
                    menu();
                }

            }
        }
        else
        {
            cout << "Bledny login lub haslo";
        }
        break;
    default:
        break;
    }

    return 0;
}

int Alarm::menu()
{
    int option = -1;
    int a = -1;
    int b = -1;
    int i = -1;
    int j = -1;


    do
    {
        system("cls");;
        cout << "Zalogowany jako: " << user << endl;
        cout << "Numer dostepu: " << acc << endl;
        cout << "Wybierz co chcesz zrobic: " << endl;
        cout << "1. Wyswietl wszystkie czujniki" << endl;
        cout << "2. Sprawdz czujniki" << endl;
        cout << "3. Edycja drzewa czujnikow" << endl;
        cout << "4. Wyswietl uzytkownikow" << endl;
        cout << "5. Edycja uzytkownikow" << endl;
        cout << "6. Raporty" << endl;
        cout << "7. Zaloguj siê ponownie" << endl;
        cout << endl << "0. Wyjscie" << endl;
        cout << "Wybor" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            if(acc=="admin")
                cout << "Czujniki:" << endl;
            list_zones->showAll();
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Aktywny Czujnik:" << endl;
            check();
            system("pause");
            break;
        case 3:
            system("cls");
            if(acc=="admin")
            {
                cout << "Edycja drzewa czujnikow:" << endl;
                cout << "1. Edycja Stref" << endl;
                cout << "2. Edycja Obiektow" << endl;
                cout << "3. Edycja Czujnikow" << endl;
                a = -1;
                cin >> a;
                switch (a)
                {
                case 1:
                    system("cls");
                    cout << "Edycja Stref:" << endl;
                    cout << "1. Dodaj Strefe" << endl;
                    cout << "2. Edytuj Strefe" << endl;
                    cout << "3. Usun Strefe" << endl;
                    cout << "4. Aktywuj"<< endl;
                    b = -1;
                    cin >> b;
                    switch (b)
                    {
                    case 1:
                        cout << "Dodaj Strefe:" << endl;
                        if (list_zones->add_Zone())
                            cout << "Sukcess" << endl;
                        else cout << "Wystapil problem" << endl;
                        break;
                    case 2:
                        cout << "Edytuj Strefe:" << endl;
                        if (list_zones->edit_Zone())
                            cout << "Sukcess" << endl;
                        else cout << "Wystapil problem" << endl;
                        break;
                    case 3:
                        cout << "Usun Strefe:" << endl;
                        if (list_zones->delete_Zone())
                            cout << "Sukcess" << endl;
                        else cout << "Wystapil problem" << endl;
                        break;
                    default:
                        break;
                    }
                    break;
                case 2:
                    system("cls");
                    cout << "Edycja Obiektow" << endl;
                    cout << "1. Dodaj Obiekt" << endl;
                    cout << "2. Edytuj Obiekt" << endl;
                    cout << "3. Usun Obiekt" << endl;
                    b = -1;
                    cin >> b;
                    switch (b)
                    {
                    case 1:
                        cout << "Dodaj Obiekt:" << endl;
                        cout << "W ktorej Strefie?" << endl;
                        for (size_t i = 0; i < list_zones->zones.size(); i++)
                            cout << i << ". Nazwa" << list_zones->zones.at(i).name << " ID: " << list_zones->zones.at(i).id << endl;
                        cout << "Wybor: ";
                        i = -1;
                        cin >> i;
                        if (i <= list_zones->zones.size() && i >-1)
                            if (list_zones->zones.at(i).add_Object())
                                cout << "Sukcess" << endl;
                            else cout << "Wystapil problem" << endl;
                        else cout << "Wystapil problem" << endl;
                        break;
                    case 2:
                        cout << "Edytuj Obiekt:" << endl;
                        cout << "W ktorej Strefie?" << endl;
                        for (size_t i = 0; i < list_zones->zones.size(); i++)
                            cout << i << ". Nazwa" << list_zones->zones.at(i).name << " ID: " << list_zones->zones.at(i).id << endl;
                        cout << "Wybor: ";
                        i = -1;
                        cin >> i;
                        if (i <= list_zones->zones.size() && i >-1)
                        {
                            if (list_zones->zones.at(i).edit_Object())
                            {
                                cout << "Sukcess" << endl;
                            }
                            else cout << "Wystapil problem" << endl;

                        }
                        break;
                    case 3:
                        cout << "Usun Obiekt:" << endl;
                        cout << "W ktorej Strefie?" << endl;
                        for (size_t i = 0; i < list_zones->zones.size(); i++)
                            cout << i << ". Nazwa" << list_zones->zones.at(i).name << " ID: " << list_zones->zones.at(i).id << endl;
                        cout << "Wybor: ";
                        i = -1;
                        cin >> i;
                        if (i <= list_zones->zones.size() && i >-1)
                            if (list_zones->zones.at(i).delete_Object())
                            {
                                cout << "Sukcess" << endl;
                            }
                            else cout << "Wystapil problem" << endl;
                        else cout << "Wystapil problem" << endl;
                        break;
                    default:
                        break;
                    }
                    break;
                case 3:
                    system("cls");
                    cout << "Edycja Czujnikow" << endl;
                    cout << "1. Dodaj Czujnik" << endl;
                    cout << "2. Edytuj Czujnik" << endl;
                    cout << "3. Usun Czujnik" << endl;
                    b = -1;
                    cin >> b;
                    switch (b)
                    {
                    case 1:
                        cout << "Dodaj Czujnik:" << endl;
                        cout << "W ktorej Strefie?" << endl;
                        for (size_t i = 0; i < list_zones->zones.size(); i++)
                            cout << i << ". Nazwa" << list_zones->zones.at(i).name << " ID: " << list_zones->zones.at(i).id << endl;
                        cout << "Wybor: ";
                        i = -1;
                        cin >> i;
                        if (i <= list_zones->zones.size() && i >-1)
                        {
                            cout << "W ktorym Obiekcie?" << endl;
                            for (size_t j = 0; j < list_zones->zones.at(i).objects.size(); j++)
                                cout << j << ". Nazwa" << list_zones->zones.at(i).objects.at(j).name << " ID: " << list_zones->zones.at(i).objects.at(j).id << endl;
                            j = -1;
                            cout << "Wybor: ";
                            cin >> j;

                            if (j <= list_zones->zones.at(i).objects.size() && j>-1)
                            {
                                if (list_zones->zones.at(i).objects.at(j).add_sensor())
                                {
                                    cout << "Sukcess" << endl;
                                }
                                else cout << "Wystapil problem" << endl;
                            }
                            else cout << "Wystapil problem" << endl;
                        }
                        else cout << "Wystapil problem" << endl;
                        break;
                    case 2:
                        cout << "Edytuj Czujnik:" << endl;
                        cout << "W ktorej Strefie?" << endl;
                        for (size_t i = 0; i < list_zones->zones.size(); i++)
                            cout << i << ". Nazwa" << list_zones->zones.at(i).name << " ID: " << list_zones->zones.at(i).id << endl;
                        cout << "Wybor: ";
                        i = -1;
                        cin >> i;
                        if (i <= list_zones->zones.size() && i >-1)
                        {
                            cout << "W ktorym Obiekcie?" << endl;
                            for (size_t j = 0; j < list_zones->zones.at(i).objects.size(); j++)
                                cout << j << ". Nazwa" << list_zones->zones.at(i).objects.at(j).name << " ID: " << list_zones->zones.at(i).objects.at(j).id << endl;
                            j = -1;
                            cout << "Wybor: ";
                            cin >> j;

                            if (j <= list_zones->zones.at(i).objects.size() && j>-1)
                            {
                                if (list_zones->zones.at(i).objects.at(j).edit_sensor())
                                    cout << "Sukcess" << endl;
                                else cout << "Wystapil problem" << endl;
                            }
                            else cout << "Wystapil problem" << endl;
                        }
                        else cout << "Wystapil problem" << endl;
                        break;
                    case 3:
                        cout << "Usun Czujnik:" << endl;
                        cout << "W ktorej Strefie?" << endl;
                        for (size_t i = 0; i < list_zones->zones.size(); i++)
                            cout << i << ". Nazwa" << list_zones->zones.at(i).name << " ID: " << list_zones->zones.at(i).id << endl;
                        cout << "Wybor: ";
                        i = -1;
                        cin >> i;
                        if (i <= list_zones->zones.size() && i >-1)
                        {
                            cout << "W ktorym Obiekcie?" << endl;
                            for (size_t j = 0; j < list_zones->zones.at(i).objects.size(); j++)
                                cout << j << ". Nazwa" << list_zones->zones.at(i).objects.at(j).name << " ID: " << list_zones->zones.at(i).objects.at(j).id << endl;
                            j = -1;
                            cout << "Wybor: ";
                            cin >> j;
                            if (j <= list_zones->zones.at(i).objects.size() && j >-1)
                            {
                                if (list_zones->zones.at(i).objects.at(j).delete_sensor())
                                {
                                    cout << "Sukcess" << endl;
                                }
                                else cout << "Wystapil problem" << endl;
                            }
                            else cout << "Wystapil problem" << endl;
                        }
                        else cout << "Wystapil problem" << endl;
                        break;
                    default:
                        break;
                    }
                }
                list_zones->save();
                system("pause");
                break;
            }
            else
            {
                cout<<"ta opcja jest tylko dla administratora"<<endl;
                system("pause");
                break;
            }

        case 4:
            if (list_users->users.size() > 0)
            {
                system("cls");
                cout << "Wyswietl uzytkownikow" << endl;
                for (size_t i = 0; i < list_users->users.size(); i++)
                {
                    cout << i << ". Nazwa: " << list_users->users.at(i).show_name() << " ID:  " << list_users->users.at(i).show_id() << " Access:  " << list_users->users.at(i).access << endl;
                }
                system("pause");
            }
            break;
        case 5:
            system("cls");
            if (acc=="admin")
            {
                cout << "Edycja uzytkownikow:" << endl;
                cout << "1. Dodaj uzytkownika" << endl;
                cout << "2. Edytuj uzytkownika" << endl;
                cout << "3. Usun uzytkownika" << endl;
                a = -1;
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "Dodaj uzytkownika:" << endl;
                    if (list_users->add_User())
                        cout << "Sukcess" << endl;
                    else cout << "Wystapil problem" << endl;
                    break;
                case 2:
                    cout << "Edytuj uzytkownika:" << endl;
                    if (list_users->edit_User())
                        cout << "Sukcess" << endl;
                    else cout << "Wystapil problem" << endl;
                    break;
                case 3:
                    cout << "Usun uzytkownika:" << endl;
                    if (list_users->delete_User())
                    {
                        cout << "Sukcess" << endl;
                    }
                    else cout << "Wystapil problem" << endl;
                    break;
                default:
                    break;
                }
                system("pause");
                break;
            }
            else
            {
                cout<< "Ta opcja dostepna jest tylko dla administratora"<< endl;
                system("pause");
                break;
            }
        case 6:
            system("cls");
            cout << "Raporty:" << endl;
            cout << read_Raports();
            system("pause");
            break;
        case 7:
            system ("cls");
            login();
            system("pause");
            break;
        default:
            break;
        }
    }
    while (option != 0);
    system("pause");
    return 0;
}

int Alarm::check()
{
    temp[0] = -1;
    temp[1] = -1;
    temp[2] = -1;
    if ((list_zones->is_active()) == temp)
    {
        cout << "Brak aktywnych czujnikow" << endl;
        return 1;
    }
    else
    {
        temp[0] = list_zones->is_active()[0];
        temp[1] = list_zones->is_active()[1];
        temp[2] = list_zones->is_active()[2];
        string tmp;
        tmp.clear();
        tmp.append(list_zones->showWhere(temp[0], temp[1], temp[2]));
        time_t czas;
        struct tm * data;
        char godzina[80];
        time(&czas);
        data = localtime(&czas);
        strftime(godzina, 80, "%c Zdarzenie: ", data);
        tmp.insert(0, godzina);
        cout << tmp;
        save_Raports(tmp);
        return 0;
    }
}

void Alarm::save_Raports(string save)
{
    fstream file("Raport", ios::app);
    if (file.good())
    {
        file.write(&save[0], save.size());
        file.flush();
    }
    file.close();
}

string Alarm::read_Raports()
{
    string tmp = "Puste";
    ifstream file;
    file.open("Raport");
    if (!file.good())
        return tmp;
    tmp.clear();
    string c;
    c.clear();
    while (!file.eof())
    {
        cin.sync();
        getline(file, c);
        tmp += (c + "\n");
    }
    file.close();
    return tmp;
}
