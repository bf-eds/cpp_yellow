#include <iostream>
#include <vector>
#include <limits>
#include <set>

using namespace std;

void foo()
{
    cout << "asdf";
    throw runtime_error("");
}


int main()
{
    set<string> s = {"123", "asdf", "432"};
//    set<string> s;
    auto range = s.equal_range("asf");

    cout << (range.first == range.second) << endl;


    return 0;
}