//
// Created by d.eroshenkov on 19.10.2018.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void PrintVector(vector<int> v)
{
    for (auto item : v)
    {
        cout << item << " ";
    }

    cout << endl;
}

int main()
{
    unsigned int n = 0;
    cin >> n;

    if (n > 9)
    {
        return 0;
    }

    vector<int> nums(n);
    for (size_t i = 0; i < nums.size(); ++i)
    {
        nums[i] = nums.size() - i;
    }

    do
    {
        PrintVector(nums);
    }
    while (std::prev_permutation(nums.begin(), nums.end()));

    return 0;
}

