//
// Created by d.eroshenkov on 23.10.2018.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end);

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if ((range_end - range_begin) < 2)
    {
        return;
    }

    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto elements_middle = elements.begin() + (range_end - range_begin) / 2;
    MergeSort(elements.begin(), elements_middle);
    MergeSort(elements_middle, elements.end());
    merge(elements.begin(), elements_middle, elements_middle, elements.end(), range_begin);
}

int main()
{
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}