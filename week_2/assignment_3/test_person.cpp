//
// Created by human on 11.10.2018.
//

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template<class T>
ostream &operator<<(ostream &os, const vector<T> &s)
{
    os << "{";
    bool first = true;
    for (const auto &x : s)
    {
        if (!first)
        {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class T>
ostream &operator<<(ostream &os, const set<T> &s)
{
    os << "{";
    bool first = true;
    for (const auto &x : s)
    {
        if (!first)
        {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class K, class V>
ostream &operator<<(ostream &os, const map<K, V> &m)
{
    os << "{";
    bool first = true;
    for (const auto &kv : m)
    {
        if (!first)
        {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint = {})
{
    if (t != u)
    {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty())
        {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string &hint)
{
    AssertEqual(b, true, hint);
}

class TestRunner
{
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string &test_name)
    {
        try
        {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception &e)
        {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...)
        {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner()
    {
        if (fail_count > 0)
        {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

/*
class Person
{
public:
    void ChangeFirstName(int year_, const string &first_name)
    {
        // добавить факт изменения имени на first_name в год year_
        records[year_].firstName = first_name;
    }

    void ChangeLastName(int year_, const string &last_name)
    {
        // добавить факт изменения фамилии на last_name в год year_
        records[year_].lastName = last_name;
    }

    string GetFullName(int year_)
    {
        // получить имя и фамилию по состоянию на конец года year_

        string first;
        string last;

        for (auto item : records)
        {
            if (item.first <= year_)
            {
                if (!item.second.firstName.empty())
                {
                    first = item.second.firstName;
                }

                if (!item.second.lastName.empty())
                {
                    last = item.second.lastName;
                }
            }
            else
            {
                break;
            }
        }

        string result;

        if (first.empty())
        {
            if (last.empty())
            {
                result = "Incognito";
            }
            else
            {
                result = last + " with unknown first name";
            }
        }
        else if (last.empty())
        {
            result = first + " with unknown last name";
        }
        else
        {
            result = first + " " + last;
        }

        return result;
    }

private:
    struct Name
    {
        string firstName;
        string lastName;
    };
    map<int, Name> records;
};*/

void TestFirstNameOnly()
{
    Person p;
    int year = 2020;
    string name = "Name";
    p.ChangeFirstName(year, name);
    AssertEqual(p.GetFullName(year), name + " with unknown last name");
}

void TestLastNameOnly()
{
    Person p;
    int year = 2028;
    string last_name = "Last Name";
    p.ChangeLastName(year, last_name);
    AssertEqual(p.GetFullName(year), last_name + " with unknown first name");
}

void TestBothNames()
{
    Person p;
    int year = 103;
    string last_name = "Last Name";
    string first_name = "First Name";
    p.ChangeLastName(year, last_name);
    p.ChangeFirstName(year, first_name);
    AssertEqual(p.GetFullName(year), first_name + " " + last_name);
}

void TestBothNames2()
{
    Person p;
    string first_name = "Polina";
    string last_name = "Sergeeva";
    p.ChangeFirstName(1965, first_name);
    p.ChangeLastName(1967, last_name);
    AssertEqual(p.GetFullName(1900), "Incognito");
    AssertEqual(p.GetFullName(1965), first_name + " with unknown last name");
    AssertEqual(p.GetFullName(1990), first_name + " " + last_name);
}

void TestNoNames()
{
    Person p;
    int year = 13;
    AssertEqual(p.GetFullName(year), "Incognito");
}

int main()
{
    TestRunner runner;
    runner.RunTest(TestFirstNameOnly, "TestFirstName");
    runner.RunTest(TestLastNameOnly, "TestLastNameOnly");
    runner.RunTest(TestNoNames, "TestNoNames");
    runner.RunTest(TestBothNames, "TestBothNames");
    runner.RunTest(TestBothNames2, "TestBothNames2");
    return 0;
}
