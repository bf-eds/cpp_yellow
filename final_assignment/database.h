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
        int prev_size = unordered_records_.size();
        auto remove_begin = remove_if(unordered_records_.begin(), unordered_records_.end(), predicate);
//        remove(remove_beign, unordered_records_.end());
        unordered_records_.erase(remove_begin, unordered_records_.end());
        int count = unordered_records_.size() - prev_size;


        /* TODO: удалить из вектора тоже, использовать stable_partition. */

        return 0;
    }

    template<typename Predicate>
    vector<string> FindIf(Predicate predicate) const
    {
        return {};
    }

    const string Last(const Date &date) const;

    int Size() const
    {
        return unordered_records_.size();
    }

private:
//    map<Date, pair<set<string>, vector<string>>> records_;
    map<Date, set<string>> unordered_records_;
    map<Date, vector<string>> ordered_records_;
};

void TestDatabase();