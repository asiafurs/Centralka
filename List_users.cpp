#include "List_users.h"
#include <string>
List_users::List_users()
{
}


List_users::~List_users()
{
}
bool List_users::add_User()
{
    string username, password, access;
    int option = -1;
    cout << "Dodaj uzytkownika" << endl;
    cout << "Wprowadz login:" << endl;
    cin >> username;
    cout << "Wprowadz haslo" << endl;
    cin >> password;
    cout << "Wybierz dostep" << endl;
    cout << "1.Administrator" << endl;
    cout << "2.Serwisant" << endl;
    cout << "3.Uzytkownik" << endl;
    cout << "Wybor" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        cout << "Wybrales administratora" << endl;
        access="admin";
        break;
    case 2:
        cout << "Wybrales serwisanta" << endl;
        access="serwisant";
        break;
    case 3:
        cout << "Wybrales uzytkownika" << endl;
        access="uzytkownik";
        break;
    default:
        return false;
        break;
    }
    users.push_back(User(users.size(),username, access, password));
    save();
    return true;
}

bool List_users::edit_User()
{
    if (users.size() > 0)
    {
        cout << "Ktory obiekt edytowac?" << endl;
        for (size_t i = 0; i < users.size(); i++)
        {
            cout << i << ". Nazwa: " << users.at(i).show_name() << " ID:  " << users.at(i).show_id() << endl;
        }
        int temp;
        cin >> temp;
        if (temp >= users.size())
            cout << "Bledny wybor!" << endl;
        else
        {
            string username, password;
            char option = ' ';
            cout << "Edytuj uzytkownika: " << users.at(temp).name<< endl;
            cout << "Wprowadz login:" << endl;
            cin >> users.at(temp).name;
            cout << "Wprowadz haslo" << endl;
            cin >> users.at(temp).password;
            cout << "Wybierz dostep" << endl;
            cout << "1.Administrator" << endl;
            cout << "2.Serwisant" << endl;
            cout << "3.Uzytkownik" << endl;
            cout << "Wybor" << endl;
            cin >> option;
            switch (option)
            {
            case '1':
                cout << "Wybrales administratora" << endl;
                users.at(temp).access="admin" ;
                break;
            case '2':
                cout << "Wybrales serwisanta" << endl;
                users.at(temp).access ="serwisant";
                break;
            case '3':
                cout << "Wybrales uzytkownika" << endl;
                users.at(temp).access ="uzytkownik";
                break;
            default:
                return false;
                break;
            }

        }
    }
    save();
    return true;
}

bool List_users::delete_User()
{
    if (users.size() > 0)
    {
        cout << "Ktory obiekt usunac?" << endl;
        for (size_t i = 0; i < users.size(); i++)
        {
            cout << i << ". Nazwa: " << users.at(i).show_name() << " ID:  " << users.at(i).show_id() << endl;
        }
        int temp;
        cin >> temp;
        if (temp >= users.size() || temp < 0)
        {
            cout << "Bledny wybor!" << endl;
            return false;
        }
        else
            users.erase(users.begin() + temp);
    }
    save();
    return true;
}

bool List_users::search(string login, string pass)
{

    if (users.size() > 0)
    {
        for (size_t i = 0; i < users.size(); i++)
        {
            if (users.at(i).show_name() == login && users.at(i).password == pass)
            {
                return true;
            }
        }
    }
    else
    {
        string passw;
        cout << "Wprowadz haslo programowe" << endl;
        cin >> passw;
        if (passw == ("zxc"))
        {
            return true;
        }
    }
    return false;
}


bool List_users::read()
{
    ifstream file;
    file.open("users");
    if (!file.good())
        return false;
    string name,password, access;
    int id;

    while (true) //petla nieskonczona
    {
        file >> id >> name >> password >> access;
        if (file.good())
        {
            users.push_back(User(id, name,access, password));
        }

        else if(!file.fail())
        {
            std::cout << "Nie udalo sie wczytac uzytkownikow" << std::endl;
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

bool List_users::save()
{
    fstream file("users", ios::out);
    if (file.good())
    {
        for (size_t i = 0; i <users.size(); i++)
        {
            file << users.at(i).id<<" "<< users.at(i).name << " "<< users.at(i).password << " " <<users.at(i).access  <<endl;
            file.flush();
        }
        file.close();
    }
    return true;
}
