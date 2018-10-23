//
// Created by d.eroshenkov on 19.10.2018.
//

#include <vector>
#include <set>
#include <iostream>

using namespace std;

template<typename T>
void RemoveDuplicates(vector<T> &elements)
{
    set<T> s(elements.begin(), elements.end());
    elements.assign(s.begin(), s.end());
}

//int main()
//{
//    vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
//    RemoveDuplicates(v1);
//    for (int x : v1)
//    {
//        cout << x << " ";
//    }
//    cout << endl;
//
//    vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
//    RemoveDuplicates(v2);
//    for (const string &s : v2)
//    {
//        cout << s << " ";
//    }
//    cout << endl;
//    return 0;
//}