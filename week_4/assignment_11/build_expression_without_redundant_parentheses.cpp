//
// Created by human on 26.10.2018.
//

#include <iostream>
#include <queue>

using namespace std;

struct operation
{
    string name;
    int precedence = 0;
};

int main()
{
    queue<operation> expression;
    int x = 0;
    cin >> x;
    expression.push({to_string(x), 3});

    unsigned int num = 0;
    cin >> num;
    cin.get();
    unsigned int parenthesesNum = 0;
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

        operation prev = expression.back();

        if (prev.precedence < line.precedence)
        {
            parenthesesNum++;
        }

        expression.push(line);
    }

    if (expression.size() == 1)
    {
        cout << expression.front().name << endl;
    }
    else
    {
        cout << string(parenthesesNum, '(');

        while (!expression.empty())
        {
            operation str = expression.front();
            expression.pop();
            cout << str.name;

            if (str.precedence < expression.front().precedence)
            {
                cout << ") ";
            }
            else
            {
                cout << " ";
            }
        }
    }

    return 0;
}