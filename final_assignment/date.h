//
// Created by human on 10.11.2018.
//

#pragma once

#include <string>

using namespace std;

class Date
{
public:
    Date(const int year = 0, const int month = 0, const int day = 0) : year_(year), month_(month), day_(day)
    {
    }

    const string GetString() const;

    int GetYear() const
    {
        return year_;
    }

    int GetMonth() const
    {
        return month_;
    }

    int GetDay() const
    {
        return day_;
    }

private:
    const int year_;
    const int month_;
    const int day_;

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