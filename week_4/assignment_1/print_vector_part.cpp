//
// Created by d.eroshenkov on 18.10.2018.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void PrintVectorPart(const vector<int> &numbers)
{
    auto item = find_if(numbers.begin(), numbers.end(), [](const int num)
    { return (num < 0); });

    while (item != begin(numbers))
    {
        cout << *(--item) << " ";
    }
    cout << endl;
}

int main()
{
    PrintVectorPart({6, 1, 8, -5, 4});
    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
    PrintVectorPart({6, 1, 8, 5, 4});
    return 0;
}