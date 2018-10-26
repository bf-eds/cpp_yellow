//
// Created by d.eroshenkov on 26.10.2018.
//

#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int> &numbers, int border)
{
    auto const lower = numbers.lower_bound(border);

    if (lower == numbers.begin())
    {
        return lower;
    }

    auto const previous = prev(lower);

    if (lower == numbers.end())
    {
        return previous;
    }

    return (border - *previous <= *lower - border) ? previous : lower;
}

//int main()
//{
//    set<int> numbers = {1, 4, 6};
//    cout << *FindNearestElement(numbers, 0) << " " << *FindNearestElement(numbers, 3) << " "
//         << *FindNearestElement(numbers, 5) << " " << *FindNearestElement(numbers, 6) << " "
//         << *FindNearestElement(numbers, 100) << endl;
//
//    set<int> empty_set;
//
//    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
//    return 0;
//}