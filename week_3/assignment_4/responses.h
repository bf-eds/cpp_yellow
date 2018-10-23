//
// Created by d.eroshenkov on 17.10.2018.
//

#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

struct BusesForStopResponse
{
    vector<string> buses;
};

struct StopsForBusResponse
{
    vector<string> buses_stops;
    map<string, vector<string>> stops;
};

struct AllBusesResponse
{
    map<string, vector<string>> all_buses;
};

ostream &operator<<(ostream &os, const BusesForStopResponse &r);
ostream &operator<<(ostream &os, const StopsForBusResponse &r);
ostream &operator<<(ostream &os, const AllBusesResponse &r);