#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class F
{
public:
    int a;
    int b;
    void operator+(F &obj)
    {
        // cout << "printing operation" << endl;
        int v1 = this->a;
        int v2 = obj.a;
        cout << "sub " << v2 - v1 << endl;
    }
};

int main()
{
    F obj1, obj2;
    obj1.a = 3;
    obj2.a = 9;

    obj1 + obj2;
};