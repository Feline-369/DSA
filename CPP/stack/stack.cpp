#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class stack
{
public:
    int size;
    int *arr;
    int top;
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    int push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }
    int pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "stack underflow" << endl;
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "stack empty" << endl;
            return -1;
        }
    }
    bool empty()
    {
        if (top > -1)
        {
            return true;
        }
        else
        {
            return false
        }
    }
};

int main()
{
    stack st[5];
    st.push(36);
    st.push(93);
    st.push(69);
    // creation of stack using stl
    /*
    stack<int> s;
    s.push(3);
    s.push(6);
    s.push(9);
    s.push(0);

    s.pop();

    cout << "top " << s.top() << endl;

    if (s.empty())
    {
        cout << "stack empty" << endl;
    }
    else
    {
        cout << "stack not empty" << endl;
    }

    cout << "stack size " << s.size() << endl;
    */
    return 0;
}