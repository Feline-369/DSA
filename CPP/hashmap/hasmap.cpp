#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{

    // creation
    // unordered_map<string, int> m;
    map<string, int> m;

    // insertion

    // 1
    pair<string, int> p = make_pair("feline", 3);

    // 2

    pair<string, int> p1("cats", 1);

    // 3
    m["felicidae"] = 4;

    // update
    m["cats"] = 10;

    // search(also reverse order and run)
    cout << m["lions"] << endl;
    // cout << m.at("lion") << endl;

    // size
    cout << m.size() << endl;
    cout << m.count("cats") << endl;

    // erase
    m.erase("cats");
    cout << m.size() << endl;

    // iterator
    // unordered_map<string, int>::iterator it = m.begin();
    map<string, int>::iterator it = m.begin();

    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
}