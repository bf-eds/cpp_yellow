//
// Created by d.eroshenkov on 11.10.2018.
//

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <math.h>

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
int GetDistinctRealRootCount(double a, double b, double c)
{
    double d; // Объявляем переменные с плавающей точкой.

    if (!a)
    {
        if (b != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    d = b * b - 4 * a * c; // Рассчитываем дискриминант
    if (d > 0) // Условие при дискриминанте больше нуля
    {
//        x1 = ((-b) + sqrt(d)) / (2 * a);
//        x2 = ((-b) - sqrt(d)) / (2 * a);

        return 2;
//        cout << "x1 = " << x1 << "\n";
//        cout << "x2 = " << x2 << "\n";
    }
    else if (d == 0) // Условие для дискриминанта равного нулю
    {
//        x1 = -(b / (2 * a));
//        cout << "x1 = x2 = " << x1 << "\n";
        return 1;
    }
    else
    { // Условие при дискриминанте меньше нуля
//        cout << "D < 0, Действительных корней уравнения не существует";
        return 0;
    }
}*/

void TestAEqualZero()
{
    AssertEqual(GetDistinctRealRootCount(0, 1, 1), 1);
}

void TestABEqualZero()
{
    AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0);
}

void TestDLessThanZero()
{
    AssertEqual(GetDistinctRealRootCount(2, 3, 3), 0);
}

void TestDMoreThanZero()
{
    AssertEqual(GetDistinctRealRootCount(2, 6, 4), 2);
}

void TestDEqualZero()
{
    AssertEqual(GetDistinctRealRootCount(1, 2, 1), 1);
}

int main()
{
    TestRunner runner;
    runner.RunTest(TestAEqualZero, "TestAEqualZero");
    runner.RunTest(TestABEqualZero, "TestABEqualZero");
    runner.RunTest(TestDLessThanZero, "TestDLessThanZero");
    runner.RunTest(TestDMoreThanZero, "TestDMoreThanZero");
    runner.RunTest(TestDEqualZero, "TestDEqualZero");
    return 0;
}
