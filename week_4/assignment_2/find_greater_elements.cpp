//
// Created by d.eroshenkov on 18.10.2018.
//

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
vector<T> FindGreaterElements(const set<T> &elements, const T &border)
{
    auto border_it = find_if(elements.begin(), elements.end(), [border](const T &item)
    { return item > border; });

    if (border_it == elements.end())
    {
        return {};
    }
    else
    {
        return vector<T>(border_it, elements.end());
    }
}

//int main()
//{
//    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5))
//    {
//        cout << x << " ";
//    }
//    cout << endl;
//
//    for (int x : FindGreaterElements(set<int>{1, 2, 4, 5, 6, 7}, 3))
//    {
//        cout << x << " ";
//    }
//    cout << endl;
//
//    string to_find = "Python";
//    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
//    return 0;
//}