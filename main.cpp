#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    cout << numeric_limits<int>::min() << ":" << numeric_limits<int>::max() << endl;
//    cout << (-1 < 1u) << endl;
    return 0;
}