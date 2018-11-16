//
// Created by human on 10.11.2018.
//

#include "database.h"
#include "test_runner.h"
#include <iostream>

void Database::Add(const Date &date, const string &event)
{
    if (event.empty() || (date.GetString() == "0000-00-00"))
    {
        return;
    }

//    size_t prev = unordered_records_[date].first.size();
//    unordered_records_[date].first.insert(event);
//
//    if (prev < unordered_records_[date].first.size())
//    {
//        unordered_records_[date].second.push_back(event);
//    }

    size_t prev = unordered_records_[date].size();
    unordered_records_[date].insert(event);

    if (prev < unordered_records_[date].size())
    {
        ordered_records_[date].push_back(event);
    }

}

void Database::Print(ostream &os) const
{
    for (const auto &record : ordered_records_)
    {
        Date d = record.first;
        string str = d.GetString();

        for (const auto &event:record.second)
        {
            os << str + " " + event << endl;
        }
    }
}

const string Database::Last(const Date &date) const
{
    auto upper = ordered_records_.upper_bound(date);

    if (upper != ordered_records_.begin())
    {
        upper--;
    }
    else
    {
        return "No entries";
    }

    return (*upper).first.GetString() + " " + (*upper).second.back();
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