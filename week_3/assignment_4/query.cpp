//
// Created by d.eroshenkov on 17.10.2018.
//
#include "query.h"
#include <iostream>

istream &operator>>(istream &is, Query &q)
{
    string op_code;
    is >> op_code;
    Query query;

    if (op_code == "NEW_BUS")
    {
        query.type = QueryType::NewBus;
        int stop_count = 0;
        is >> query.bus;
        is >> stop_count;
        query.stops.resize(stop_count);
        for (string &stop : query.stops)
        {
            is >> stop;
        }

    }
    else if (op_code == "BUSES_FOR_STOP")
    {
        query.type = QueryType::BusesForStop;
        is >> query.stop;
    }
    else if (op_code == "STOPS_FOR_BUS")
    {
        query.type = QueryType::StopsForBus;
        is >> query.bus;
    }
    else if (op_code == "ALL_BUSES")
    {
        query.type = QueryType::AllBuses;
    }

    if (is)
    {
        q = query;
    }

    return is;
}