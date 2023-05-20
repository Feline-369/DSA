#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Human
{
public:
    int height;
    int weight;
    int function()
    {
        return height / weight;
    }
};

class male : public Human
{
    int bmi;
};

int main()
{
    male m1;
    cout << m1.height << endl;
};