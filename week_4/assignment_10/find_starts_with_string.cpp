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
    return equal_range(range_begin, range_end, prefix, [prefix](const string &s1, const string &s2)
    {
        if (prefix == s1)
        {
            if (prefix > s2)
            {
                return false;
            }
            else
            {
                return !(s2.substr(0, prefix.size()) == prefix);
            }
        }
        else
        {
            return (prefix > s1);
        }
    });
}


//int main()
//{
////    const vector<string> sorted_strings = {"a", "cdaa", "cdasdfasdf"};
//////    const vector<string> sorted_strings = {};
////
////    const auto mo_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "cd");
////    for (auto it = mo_result.first; it != mo_result.second; ++it)
////    {
////        cout << *it << " ";
////    }
////    cout << endl;
////
////    auto mt_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "aa");
////    cout << (mt_result.first - begin(sorted_strings)) << " " << (mt_result.second - begin(sorted_strings)) << endl;
////
////    auto na_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "b");
////    cout << (na_result.first - begin(sorted_strings)) << " " << (na_result.second - begin(sorted_strings)) << endl;
////
////    na_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "c");
////    cout << (na_result.first - begin(sorted_strings)) << " " << (na_result.second - begin(sorted_strings)) << endl;
////
////     na_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "0");
////    cout << (na_result.first - begin(sorted_strings)) << " " << (na_result.second - begin(sorted_strings)) << endl;
////
////    na_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "z");
////    cout << (na_result.first - begin(sorted_strings)) << " " << (na_result.second - begin(sorted_strings)) << endl;
//
//
//
//
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
//
//
//    return 0;
//}