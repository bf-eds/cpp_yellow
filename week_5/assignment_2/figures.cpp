//
// Created by human on 05.11.2018.
//
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>
#include <math.h>
#include <iomanip>

using namespace std;

class Figure
{
public:

    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
//private:
//    const string _name;
};

class Triangle : public Figure
{
public:
    Triangle(const string &_name, int _a, int _b, int _c) : _a(_a), _b(_b), _c(_c), _name(_name)
    {
    }

    string Name() const override
    {
        return _name;
    }

    double Perimeter() const override
    {
        return _a + _b + _c;
    }

    double Area() const override
    {
        double p = 0.5 * Perimeter();
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));
    }

private:
    int _a;
    int _b;
    int _c;
    const string _name;
};

class Rect : public Figure
{
public:
    Rect(const string &_name, int _width, int _height) : _width(_width), _height(_height), _name(_name)
    {
    }

    string Name() const override
    {
        return _name;
    }

    double Perimeter() const override
    {
        return (_width + _height) * 2;
    }

    double Area() const override
    {
        return _height * _width;
    }

private:
    int _width;
    int _height;
    const string _name;
};

class Circle : public Figure
{
public:
    Circle(const string &_name, int _r) : _r(_r), _name(_name)
    {
    }

    string Name() const override
    {
        return _name;
    }

    double Perimeter() const override
    {
        return 2 * 3.14 * _r;
    }

    double Area() const override
    {
        return 3.14 * _r * _r;
    }

private:
    int _r;
    const string _name;
};

shared_ptr<Figure> CreateFigure(istringstream &is)
{
    shared_ptr<Figure> ptr;
    string figure;
    is >> figure;

    if (figure == "RECT")
    {
        int width;
        int height;
        is >> width >> height;
        ptr = make_shared<Rect>(figure, width, height);

    }
    else if (figure == "TRIANGLE")
    {
        int a;
        int b;
        int c;
        is >> a >> b >> c;
        ptr = make_shared<Triangle>(figure, a, b, c);
    }
    else if (figure == "CIRCLE")
    {
        int r;
        is >> r;
        ptr = make_shared<Circle>(figure, r);
    }

    return ptr;
}

int main()
{
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line);)
    {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD")
        {
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT")
        {
            for (const auto &current_figure : figures)
            {
                cout << fixed << setprecision(3) << current_figure->Name() << " " << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}