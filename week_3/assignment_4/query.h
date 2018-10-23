//
// Created by d.eroshenkov on 17.10.2018.
//

#pragma once

#include <string>
#include <vector>

using namespace std;

enum class QueryType
{
    NewBus, BusesForStop, StopsForBus, AllBuses
};

struct Query
{
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream &operator>>(istream &is, Query &q);