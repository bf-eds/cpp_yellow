//
// Created by human on 10.11.2018.
//

#pragma once

#include <set>
#include <map>
#include <functional>

#include "date.h"


class Database
{
public:
    void Add(const Date &date, const string &event);
    void Print(ostream &os) const;

    template<typename Predicate>
    int RemoveIf(Predicate predicate)
    {

    }

    template<typename Predicate>
    vector<string> FindIf(Predicate predicate) const
    {

    }

    const string Last(const Date &date) const;

    int Size() const
    {
        return records_.size();
    }

private:
    map<Date, pair<set<string>, vector<string>>> records_;
};

void TestDatabase();