//
// Created by d.eroshenkov on 17.10.2018.
//

#include "responses.h"
#include <iostream>

ostream &operator<<(ostream &os, const BusesForStopResponse &r)
{
    if (r.buses.empty())
    {
        os << "No stop" << endl;
    }
    else
    {
        for (const string &bus : r.buses)
        {
            os << bus << " ";
        }
        os << endl;
    }
    return os;
}

ostream &operator<<(ostream &os, const StopsForBusResponse &r)
{
    if (r.stops.empty())
    {
        os << "No bus" << endl;
    }
    else
    {
        for (const auto &stop : r.buses_stops)
        {
            os << "Stop " << stop << ": ";
            if (r.stops.at(stop).empty())
            {
                os << "no interchange";
            }
            else
            {
                for (const string &bus : r.stops.at(stop))
                {
                    os << bus << " ";
                }
            }
            os << endl;
        }
    }
    return os;
}

ostream &operator<<(ostream &os, const AllBusesResponse &r)
{
    if (r.all_buses.empty())
    {
        os << "No buses" << endl;
    }
    else
    {
        for (const auto &bus_item : r.all_buses)
        {
            os << "Bus " << bus_item.first << ": ";
            for (const string &stop : bus_item.second)
            {
                os << stop << " ";
            }
            os << endl;
        }
    }
    return os;
}