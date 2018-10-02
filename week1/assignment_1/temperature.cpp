//
// Created by d.eroshenkov on 02.10.2018.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned int n;
    cin >> n;

    vector<int> nums(n);
    int64_t aver = 0;

    for (auto &num : nums)
    {
        cin >> num;
        aver += num;
    }

    aver /= static_cast<int>(nums.size());

    vector<int> averNum;

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] > aver)
        {
            averNum.push_back(i);
        }
    }

    cout << averNum.size() << endl;

    for (auto &num : averNum)
    {
        cout << num << " ";
    }

    return 0;
}