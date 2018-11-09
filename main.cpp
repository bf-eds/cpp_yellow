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

    int Evaluate() const override
    {
        return _x;
    }

private:
    const int &_x;
};

struct Op : public Node
{
    Op(char value) : precedence([value]
                                {
                                    if (value == '*')
                                    {
                                        return 2;
                                    }
                                    else
                                    {
                                        return 1;
                                    }
                                }()), _op(value)
    {
    }

    const uint8_t precedence;

    int Evaluate() const override
    {
        if (_op == '*')
        {
            return _left->Evaluate() * _right->Evaluate();
        }
        else if (_op == '+')
        {
            return _left->Evaluate() + _right->Evaluate();
        }
        else if (_op == '-')
        {
            return _left->Evaluate() - _right->Evaluate();
        }

        return 0;
    }

    void SetLeft(shared_ptr<Node> node)
    {
        _left = node;
    }

    void SetRight(shared_ptr<Node> node)
    {
        _right = node;
    }

private:
    const char _op;
    shared_ptr<const Node> _left, _right;
};

template<class Iterator>
shared_ptr<Node> Parse(Iterator token, Iterator end, const int &x)
{
    // Empty expression
    if (token == end)
    {
        return make_shared<Value>('0');
    }

    stack<shared_ptr<Node>> values;
    stack<shared_ptr<Op>> ops;

    auto PopOps = [&](int precedence)
    {
        while (!ops.empty() && ops.top()->precedence >= precedence)
        {
            auto value1 = values.top();
            values.pop();
            auto value2 = values.top();
            values.pop();
            auto op = ops.top();
            ops.pop();

            op->SetRight(value1);
            op->SetLeft(value2);

            values.push(op);
        }
    };

    while (token != end)
    {
        const auto &value = *token;
        if (value >= '0' && value <= '9')
        {
            values.push(make_shared<Value>(value));
        }
        else if (value == 'x')
        {
            values.push(make_shared<Variable>(x));
        }
        else if (value == '*')
        {
            PopOps(2);
            ops.push(make_shared<Op>(value));
        }
        else if (value == '+' || value == '-')
        {
            PopOps(1);
            ops.push(make_shared<Op>(value));
        }

        ++token;
    }

    while (!ops.empty())
    {
        PopOps(0);
    }

    return values.top();
}

int main()
{
    set<string> s = {"123", "asdf", "432"};
//    set<string> s;
    auto range = s.equal_range("asf");

    cout << (range.first == range.second) << endl;


    return 0;
}