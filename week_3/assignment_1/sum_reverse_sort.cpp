//
// Created by human on 15.10.2018.
//

#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y)
{
    return x + y;
}

string Reverse(string s)
{
    return string(s.rbegin(), s.rend());
}

void Sort(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
}
