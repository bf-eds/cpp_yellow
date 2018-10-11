//
// Created by human on 06.10.2018.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

template<typename T>
T Sqr(T x);

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value> &m1, const map<Key, Value> &m2);

template<typename T>
vector<T> Sqr(const vector<T> &v1, const vector<T> &v2);

template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second> &p);

template<typename T>
T Sqr(T x)
{
    return x * x;
}

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value> &m)
{
    map<Key, Value> res;
    for (const auto &item : m)
    {
        res.insert({item.first, Sqr(item.second)});
    }

    return res;
}

template<typename T>
vector<T> Sqr(const vector<T> &v)
{
    vector<T> res;
    for (auto const &item : v)
    {
        res.push_back(Sqr(item));
    }

    return res;
}

template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second> &p)
{
    return {Sqr(p.first), Sqr(p.second)};
}

int main()
{
    // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v))
    {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {{4, {2, 2}},
                                             {7, {4, 3}}};
    cout << "map of pairs:" << endl;
    for (const auto &x : Sqr(map_of_pairs))
    {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    return 0;
}
