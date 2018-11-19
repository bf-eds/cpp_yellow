//
// Created by d.eroshenkov on 26.10.2018.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string> &names, int year)
{
    auto iter_after = names.upper_bound(year);
    string name;
    if (iter_after != names.begin())
    {
        name = (--iter_after)->second;
    }
    return name;
}

class Person
{
public:
    void ChangeFirstName(int year, const string &first_name)
    {
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string &last_name)
    {
        last_names[year] = last_name;
    }

    string GetFullName(int year)
    {
        // получить имя и фамилию по состоянию на конец года year_
        // с помощью двоичного поиска

        // получаем имя и фамилию по состоянию на год year_
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        // если и имя, и фамилия неизвестны
        if (first_name.empty() && last_name.empty())
        {
            return "Incognito";

            // если неизвестно только имя
        }
        else if (first_name.empty())
        {
            return last_name + " with unknown first name";

            // если неизвестна только фамилия
        }
        else if (last_name.empty())
        {
            return first_name + " with unknown last name";

            // если известны и имя, и фамилия
        }
        else
        {
            return first_name + " " + last_name;
        }
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
};

int main()
{
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990})
    {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970})
    {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970})
    {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}