//
// Created by d.eroshenkov on 02.10.2018.
//

#include <iostream>

using namespace std;

int main()
{
    unsigned int num = 0;
    unsigned int density = 0;

    uint64_t volume = 0;

    cin >> num >> density;

    while (num--)
    {
        uint64_t w = 0;
        uint64_t d = 0;
        uint64_t h = 0;

        cin >> w >> d >> h;
        volume += (w * d * h);
    }

    cout << volume * density << endl;

    return 0;
}