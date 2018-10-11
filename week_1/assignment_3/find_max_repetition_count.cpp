//
// Created by d.eroshenkov on 02.10.2018.
//

#include <cstdint>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

enum class Lang
{
    DE, FR, IT
};

struct Region
{
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};

int FindMaxRepetitionCount(const vector<Region> &regions);

bool operator<(const Region &lhs, const Region &rhs)
{
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) < tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region> &regions)
{
    map<Region, int> counts;
    int maximum = 0;
    for (auto const &item : regions)
    {
        maximum = max(maximum, ++counts[item]);
    }

    return maximum;
}

int main()
{
    cout << FindMaxRepetitionCount(
            {{"Moscow", "Russia",  {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},  89},
             {"Russia", "Eurasia", {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}}, 89},
             {"Moscow", "Russia",  {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},  89},
             {"Moscow", "Russia",  {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},  89},
             {"Russia", "Eurasia", {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}}, 89},}) << endl;

    cout << FindMaxRepetitionCount(
            {{"Moscow", "Russia",   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},  89},
             {"Russia", "Eurasia",  {{Lang::DE, "Russland"}, {Lang::FR, "Russie"},      {Lang::IT, "Russia"}}, 89},
             {"Moscow", "Russia",   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},  89},
             {"Moscow", "Toulouse", {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},  89},
             {"Moscow", "Russia",   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},  31},})
         << endl;

    cout << FindMaxRepetitionCount({}) << endl;

    return 0;
}


