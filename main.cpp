#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void foo()
{
    cout << "asdf";
    throw runtime_error("");
}


int main()
{
    cout << numeric_limits<int>::min() << ":" << numeric_limits<int>::max() << endl;
//    cout << (-1 < 1u) << endl;


foo();
    return 0;
}