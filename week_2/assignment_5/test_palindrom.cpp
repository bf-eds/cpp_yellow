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
bool IsPalindrom(const string &str)
{
    bool result = false;
    string reverse;
    reverse = string(str.rbegin(), str.rend());
    if (reverse == str)
    {
        result = true;
    }

    return result;
}*/

void TestAll()
{
    AssertEqual(IsPalindrom(""), true, "Emtpy string.");
    AssertEqual(IsPalindrom("a"), true, "One symbol string.");
    AssertEqual(IsPalindrom("a s d s a"), true, "Palindrom with whitespaces.");
    AssertEqual(IsPalindrom("a sd s a"), false, "Not Palindrom with whitespaces.");
    AssertEqual(IsPalindrom(" sds"), false, "Not Palindrom1.");
    AssertEqual(IsPalindrom("qweew"), false, "Not Palindrom2.");
    AssertEqual(IsPalindrom(" qweq "), false, "Not Palindrom3.");
    AssertEqual(IsPalindrom(" qwe wq "), false, "Not Palindrom3.");
    AssertEqual(IsPalindrom(" qw ewq "), false, "Not Palindrom3.");
    AssertEqual(IsPalindrom("qweewq"), true, "Palindrom1.");
    AssertEqual(IsPalindrom("  "), true, "Palindrom2.");
    AssertEqual(IsPalindrom(" asdfdsa "), true, "Palindrom3.");
    AssertEqual(IsPalindrom(" asdffdsa "), true, "Palindrom3.");

    AssertEqual(IsPalindrom("madam"), 1);
    AssertEqual(IsPalindrom("lool"), 1);
    AssertEqual(IsPalindrom("o"), 1);
    AssertEqual(IsPalindrom(""), 1);
    AssertEqual(IsPalindrom(" "), 1);
    AssertEqual(IsPalindrom("  "), 1);
    AssertEqual(IsPalindrom("top pot"), 1);
    AssertEqual(IsPalindrom("o lol o"), 1);
    AssertEqual(IsPalindrom("olo lo"), 0);
    AssertEqual(IsPalindrom("ol olo"), 0);
    AssertEqual(IsPalindrom(" lolo"), 0);
    AssertEqual(IsPalindrom("olol "), 0);
    AssertEqual(IsPalindrom(" olo "), 1);
    AssertEqual(IsPalindrom("olol"), 0);
    AssertEqual(IsPalindrom("motor"), 0);
    AssertEqual(IsPalindrom("topo gun"), 0);
    AssertEqual(IsPalindrom("olol "), 0);
    AssertEqual(IsPalindrom(" lol"), 0);
    AssertEqual(IsPalindrom("olo\n"), 0);
}

int main()
{
    TestRunner runner;
    runner.RunTest(TestAll, "TestAll");
    return 0;
}
