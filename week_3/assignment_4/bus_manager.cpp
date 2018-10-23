//
// Created by d.eroshenkov on 17.10.2018.
//

#include "bus_manager.h"

void BusManager::AddBus(const string &bus, const vector<string> &stops)
{
    buses_to_stops[bus] = stops;

    for (const string &stop : stops)
    {
        stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string &stop) const
{
    if (stops_to_buses.count(stop) != 0)
    {
        return {stops_to_buses.at(stop)};
    }
    else
    {
        return {};
    }
}

StopsForBusResponse BusManager::GetStopsForBus(const string &bus) const
{
    if (buses_to_stops.count(bus) == 0)
    {
        return {};
    }

    StopsForBusResponse sb;
    sb.buses_stops = buses_to_stops.at(bus);
    for (const string &stop : sb.buses_stops)
    {
        sb.stops.insert({stop, {}});
        for (const string &other_bus : stops_to_buses.at(stop))
        {
            if (bus != other_bus)
            {
                sb.stops[stop].push_back(other_bus);
            }
        }
    }

    return sb;
}

AllBusesResponse BusManager::GetAllBuses() const
{
    return AllBusesResponse{buses_to_stops};
}
