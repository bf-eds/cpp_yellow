//
// Created by human on 26.10.2018.
//

#include <iostream>
#include <queue>

using namespace std;

struct operation
{
    string name;
    int precedence;
};

int main()
{
    queue<operation> expression;
    int x = 0;
    cin >> x;
    expression.push({to_string(x), 0});

    unsigned int num = 0;
    cin >> num;
    cin.get();
    for (unsigned int i = 0; i < num; ++i)
    {
        operation line;
        getline(cin, line.name);
        char op = line.name.front();

        if ((op == '*') || (op == '/'))
        {
            line.precedence = 2;
        }
        else
        {
            line.precedence = 1;
        }

        expression.push(line);
    }

    if (expression.size() == 1)
    {
        cout << expression.front().name << endl;
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