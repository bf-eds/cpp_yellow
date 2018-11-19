//
// Created by human on 10.11.2018.
//

#include "date.h"

#include <iomanip>
#include <vector>

#include "test_runner.h"


Date ParseDate(istream &is)
{
    int year = 0;
    int month = 0;
    int day = 0;

    is >> year;
    if (is.peek() != '-')
    {
        return {};
    }
    is.ignore(1);

    is >> month;
    if (is.peek() != '-')
    {
        return {};
    }
    is.ignore(1);

    is >> day;
    if ((is.peek() != ' ') && !is.eof())
    {
        return {};
    }

    return Date(year, month, day);
}

const string Date::GetString() const
{
    stringstream ss;
    ss << setfill('0') << setw(4) << year_ << '-' << setw(2) << month_ << '-' << setw(2) << day_;

    return ss.str();
}

ostream &operator<<(ostream &os, const Date &date)
{
    return os << date.GetString();
}

bool operator<(const Date &lhs, const Date &rhs)
{
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator==(const Date &lhs, const Date &rhs)
{
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} ==
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator<=(const Date &lhs, const Date &rhs)
{
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <=
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator>(const Date &lhs, const Date &rhs)
{
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator>=(const Date &lhs, const Date &rhs)
{
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >=
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator!=(const Date &lhs, const Date &rhs)
{
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} !=
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}


//bool operator<(const Date &lhs, const Date &rhs)
//{
//    return (lhs.GetString() < rhs.GetString());
//}
//
//bool operator==(const Date &lhs, const Date &rhs)
//{
//    return (lhs.GetString() == rhs.GetString());
//}
//
//bool operator<=(const Date &lhs, const Date &rhs)
//{
//    return (lhs.GetString() <= rhs.GetString());
//}
//
//bool operator>(const Date &lhs, const Date &rhs)
//{
//    return (lhs.GetString() > rhs.GetString());
//}
//
//bool operator>=(const Date &lhs, const Date &rhs)
//{
//    return (lhs.GetString() >= rhs.GetString());
//}
//
//bool operator!=(const Date &lhs, const Date &rhs)
//{
//    return (lhs.GetString() != rhs.GetString());
//}

void TestParseDate()
{
    {
        istringstream is("2017-11-07");
        AssertEqual(ParseDate(is).GetString(), "2017-11-07", "Parse normal date1");
    }

    {
        istringstream is("0-2-31");
        AssertEqual(ParseDate(is).GetString(), "0000-02-31", "Parse normal date2");
    }

    {
        istringstream is("02-31");
        AssertEqual(ParseDate(is).GetString(), "0000-00-00", "Parse wrong date1");
    }

    {
        istringstream is("01-231");
        AssertEqual(ParseDate(is).GetString(), "0000-00-00", "Parse wrong date2");
    }

    {
        istringstream is("01231");
        AssertEqual(ParseDate(is).GetString(), "0000-00-00", "Parse wrong date3");
    }

    {
        istringstream is("");
        AssertEqual(ParseDate(is).GetString(), "0000-00-00", "Parse null date");
    }
}


