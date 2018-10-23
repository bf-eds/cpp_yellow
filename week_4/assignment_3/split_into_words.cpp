//
// Created by d.eroshenkov on 18.10.2018.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string &s)
{
    string str = s;
    vector<string> result;
    for (auto it = find(str.begin(), str.end(), ' '); it != str.end(); it = find(str.begin(), str.end(), ' '))
    {
        result.push_back(string(str.begin(), it));
        str.erase(str.begin(), ++it);
    }

    result.push_back(str);

    return result;
}
//
//int main()
//{
//    string s = "C Cpp Java Python";
//
//    vector<string> words = SplitIntoWords(s);
//    cout << words.size() << " ";
//    for (auto it = begin(words); it != end(words); ++it)
//    {
//        if (it != begin(words))
//        {
//            cout << "/";
//        }
//        cout << *it;
//    }
//    cout << endl;
//
//    return 0;
//}