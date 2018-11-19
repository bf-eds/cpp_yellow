//
// Created by human on 10.11.2018.
//

#include "database.h"
#include "test_runner.h"
#include <iostream>

void Database::Add(const Date &date, const string &event)
{
    if (records_set[date].count(event))
    {
        return;
    }
    records_set[date].insert(event);
    records_vec[date].push_back(event);
}

void Database::Print(ostream &os) const
{
    for (const auto &record : records_vec)
    {
        string date = record.first.GetString();

        for (const auto &event : record.second)
        {
//            string str;
//            str += date;
//            str += " ";
//            str += event;
//            os << str << endl;
            os << date << " " << event << endl;
        }
    }
}

const string Database::Last(const Date &date) const
{
    auto upper = records_set.upper_bound(date);

    if (upper != records_set.begin())
    {
        upper--;
    }
    else
    {
        throw invalid_argument("");
    }

    return (*upper).first.GetString() + " " + records_vec.at((*upper).first).back();

}

void TestDatabase()
{
    {
        Database db;
        db.Add({2018, 01, 01}, "event");
        AssertEqual(db.Size(), 1, "Add event to database.");
    }

    {
        Database db;
        db.Add({2018, 01, 01}, "event");
        db.Add({2018, 01, 01}, "event");
        AssertEqual(db.Size(), 1, "Add same event to database.");
    }

    {
        Database db;
        db.Add({2018, 01, 01}, "event1");
        db.Add({2018, 01, 01}, "event2");
        AssertEqual(db.Size(), 1, "Add two events on one date to database.");
    }

    {
        Database db;
        db.Add({2018, 01, 01}, "event1");
        db.Add({2018, 01, 02}, "event2");
        AssertEqual(db.Size(), 2, "Add two events to database.");
    }

    {
        Database db;
        db.Add({}, "event1");
        AssertEqual(db.Size(), 0, "Add event without date to database.");
    }

    {
        Database db;
        db.Add({2018, 01, 01}, "");
        AssertEqual(db.Size(), 0, "Add date without event to database.");
    }
}