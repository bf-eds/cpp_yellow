//
// Created by human on 10.11.2018.
//

#pragma once

#include <string>

using namespace std;

class Date
{
public:
    Date(const int year = 0, const int month = 0, const int day = 0) : year(year), month(month), day(day)
    {
    }

    const string GetString() const;

private:
    const int year;
    const int month;
    const int day;

};

ostream &operator<<(ostream &os, const Date &date);
bool operator<(const Date &lhs, const Date &rhs);
bool operator<=(const Date &lhs, const Date &rhs);
bool operator>(const Date &lhs, const Date &rhs);
bool operator>=(const Date &lhs, const Date &rhs);
bool operator==(const Date &lhs, const Date &rhs);
bool operator!=(const Date &lhs, const Date &rhs);
Date ParseDate(istream &is);
void TestParseDate();