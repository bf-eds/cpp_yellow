//
// Created by human on 26.10.2018.
//

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<string> expression;
    int x = 0;
    cin >> x;
    expression.push(to_string(x));

    unsigned int num = 0;
    cin >> num;
    cin.get();
    for (unsigned int i = 0; i < num; ++i)
    {
        string line;
        getline(cin, line);
        expression.push(line);
    }

    if (expression.size() == 1)
    {
        cout << expression.front() << endl;
    }
    else
    {
        cout << string(num, '(');

        while (!expression.empty())
        {
            string str = expression.front();
            expression.pop();
            cout << str;
            if (!expression.empty())
            {
                cout << ") ";
            }
        }
    }

    return 0;
}