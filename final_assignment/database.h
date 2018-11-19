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
        int count = 0;

        for (auto item = records_vec.begin(); item != records_vec.end();)
        {
            /* Remove from vector. */
            auto first_false = stable_partition(item->second.begin(), item->second.end(), [&](string event)
            { return predicate(item->first, event); });

            for (auto it = item->second.begin(); it != first_false; it++)
            {
                records_set.at(item->first).erase(*it);
                count++;
            }

            item->second.erase(item->second.begin(), first_false);

            /* Check if set/vector is empty. */
            if (item->second.empty())
            {
                records_vec.erase(item->first);
                records_set.erase(item->first);
            }
            ++item;
        }

        return count;
    }

    template<typename Predicate>
    vector<string> FindIf(Predicate predicate) const
    {
        vector<string> events;

        for (auto item = records_vec.begin(); item != records_vec.end();)
        {
            for (auto set_event = item->second.begin(); set_event != item->second.end(); set_event++)
            {
                if (predicate(item->first, *set_event))
                {
                    string str = item->first.GetString();
                    str += " ";
                    str += *set_event;
                    events.push_back(str);
                }
            }
            ++item;
        }

        return events;
    }

    const string Last(const Date &date) const;

    int Size() const
    {
        return records_set.size();
    }

private:
    map<Date, set<string>> records_set;
    map<Date, vector<string>> records_vec;
};

void TestDatabase();