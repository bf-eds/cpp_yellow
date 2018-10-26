//
// Created by d.eroshenkov on 26.10.2018.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string &prefix)
{
    auto itPair = equal_range(range_begin, range_end, prefix, [prefix](const string &s1, const string &s2)
    {
        bool find = false;
        if (&prefix == &s1)
        {
            find = s2.substr(0, prefix.size()) == prefix;
        }
        else if (&prefix == &s2)
        {
            find = s1.substr(0, prefix.size()) == prefix;
        }
//        string pref;
//
//        if (s1 == prefix)
//        {
//            pref = s1;
//        }
//        else if (s2 == prefix)
//        {
//            pref = prefix;
//        }

//        auto find1 = s1.substr(0, s2.size()) == s2;
//        auto find2 = s2.substr(0, s1.size()) == s1;

//        if (find1 || find2)
        if (find)
        {
            return false;
        }
        else
        {
            return s1 < s2;
//            return true;
        }
    });

    return itPair;
}


int main()
{
    const vector<string> sorted_strings = {"a", "c", "cd"};

    const auto mo_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "c");
    for (auto it = mo_result.first; it != mo_result.second; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    auto mt_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "aa");
    cout << (mt_result.first - begin(sorted_strings)) << " " << (mt_result.second - begin(sorted_strings)) << endl;

    auto na_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "b");
    cout << (na_result.first - begin(sorted_strings)) << " " << (na_result.second - begin(sorted_strings)) << endl;

    na_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "c");
    cout << (na_result.first - begin(sorted_strings)) << " " << (na_result.second - begin(sorted_strings)) << endl;

    na_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "0");
    cout << (na_result.first - begin(sorted_strings)) << " " << (na_result.second - begin(sorted_strings)) << endl;

    na_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "z");
    cout << (na_result.first - begin(sorted_strings)) << " " << (na_result.second - begin(sorted_strings)) << endl;




//    const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
//
//    const auto mo_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
//    for (auto it = mo_result.first; it != mo_result.second; ++it)
//    {
//        cout << *it << " ";
//    }
//    cout << endl;
//
//    const auto mt_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
//    cout << (mt_result.first - begin(sorted_strings)) << " " << (mt_result.second - begin(sorted_strings)) << endl;
//
//    const auto na_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
//    cout << (na_result.first - begin(sorted_strings)) << " " << (na_result.second - begin(sorted_strings)) << endl;


    return 0;
}