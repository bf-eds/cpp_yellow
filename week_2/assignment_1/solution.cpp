//
// Created by d.eroshenkov on 09.10.2018.
//

#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

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

struct BusesForStopResponse
{
    vector<string> buses;
};

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

struct StopsForBusResponse
{
    vector<string> buses_stops;
    map<string, vector<string>> stops;
};

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

struct AllBusesResponse
{
    map<string, vector<string>> all_buses;
};

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

class BusManager
{
public:
    void AddBus(const string &bus, const vector<string> &stops)
    {
        buses_to_stops[bus] = stops;

        for (const string &stop : stops)
        {
            stops_to_buses[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string &stop) const
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

    StopsForBusResponse GetStopsForBus(const string &bus) const
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

    AllBusesResponse GetAllBuses() const
    {
        return AllBusesResponse{buses_to_stops};
    }

private:
    map<string, vector<string>> buses_to_stops;
    map<string, vector<string>> stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main()
{
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i)
    {
        cin >> q;
        switch (q.type)
        {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }

    return 0;
}
