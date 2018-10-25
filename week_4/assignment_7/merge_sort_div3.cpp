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
    int third = (range_end - range_begin) / 3;
    auto elements_first_third = elements.begin() + third;
    auto elements_second_third = elements_first_third + third;

    MergeSort(elements.begin(), elements_first_third);
    MergeSort(elements_first_third, elements_second_third);
    MergeSort(elements_second_third, elements.end());
    vector<typename RandomIt::value_type> tmp;
    merge(elements.begin(), elements_first_third, elements_first_third, elements_second_third, back_inserter(tmp));
    merge(tmp.begin(), tmp.end(), elements_second_third, elements.end(), range_begin);
}

int main()
{
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}