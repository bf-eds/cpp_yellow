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
class Rational
{
public:
    Rational()
    {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator)
    {
        numerator = new_numerator;
        denominator = new_denominator;

        if (!denominator)
        {
            throw invalid_argument("Invalid argument");
        }

        if (!numerator)
        {
            denominator = 1;
            return;
        }

        auto div = gcd(abs(numerator), abs(denominator));
        if (div != 1)
        {
            numerator /= div;
            denominator /= div;
        }

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    int Numerator() const
    {
        return numerator;
    }

    int Denominator() const
    {
        return denominator;
    }

private:
    int numerator;
    int denominator;

    int gcd(int a, int b)
    {
        while (a != b)
        {
            if (a > b)
            {
                int tmp = a;
                a = b;
                b = tmp;
            }
            b = b - a;
        }
        return a;
    }
};*/

void TestConstructor1()
{
    Rational r;
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
}

void TestConstructor2()
{
    Rational r1(4, 6);
    AssertEqual(r1.Numerator(), 2);
    AssertEqual(r1.Denominator(), 3);

    Rational r2(-8, 6);
    AssertEqual(r2.Numerator(), -4);
    AssertEqual(r2.Denominator(), 3);

    Rational r3(4, -6);
    AssertEqual(r3.Numerator(), -2);
    AssertEqual(r3.Denominator(), 3);

    Rational r4(-10, -2);
    AssertEqual(r4.Numerator(), 5);
    AssertEqual(r4.Denominator(), 1);

    Rational r5(0, 13);
    AssertEqual(r5.Numerator(), 0);
    AssertEqual(r5.Denominator(), 1);

    Rational r6(8, 2);
    AssertEqual(r6.Numerator(), 4);
    AssertEqual(r6.Denominator(), 1);

//    {
//        Rational r1(4, 6);
//        Rational r2(2, 3);
//        bool equal = r1 == r2;
//        if (!equal)
//        {
//            cout << "4/6 != 2/3" << endl;
//            return 1;
//        }
//    }
//
//    {
//        Rational a(2, 3);
//        Rational b(4, 3);
//        Rational c = a + b;
//        bool equal = c == Rational(2, 1);
//        if (!equal)
//        {
//            cout << "2/3 + 4/3 != 2" << endl;
//            return 2;
//        }
//    }
//
//    {
//        Rational a(5, 7);
//        Rational b(2, 9);
//        Rational c = a - b;
//        bool equal = c == Rational(31, 63);
//        if (!equal)
//        {
//            cout << "5/7 - 2/9 != 31/63" << endl;
//            return 3;
//        }
//    }

}

int main()
{
    TestRunner runner;
    runner.RunTest(TestConstructor1, "TestConstructor1");
    runner.RunTest(TestConstructor2, "TestConstructor2");
    return 0;
}
