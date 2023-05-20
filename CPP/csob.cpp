#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Human
{
    int height;

public:
    static int lifeSpan;
    char c = 'p';

    Human(int height)
    {
        this->height = height;
        cout << "constructor called" << endl;
    }
    int getheight()
    {
        return height;
    }
    static int function()
    {
        cout << "static funtion prints " << lifeSpan << endl;
        return lifeSpan;
    }
    ~Human()
    {
        cout << "Destructor called" << endl;
    }
};

int Human::lifeSpan = 75;

int main()
{
    // cout << "time " << Human::lifeSpan << endl;
    cout << "time " << Human::function() << endl;
    Human female(169);
    Human male = female;
    Human *f = new Human(75);
    cout << female.getheight() << endl;
    cout << f->getheight() << endl;
    cout << male.getheight() << endl;
    cout << female.c << endl;
    cout << sizeof(Human) << endl;
    delete f;
};