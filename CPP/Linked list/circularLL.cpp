#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void Insert(node *&tail, int element, int d)
{ // assume element present inside the linked list
    // empty ll
    if (tail == NULL)
    {
        node *n = new node(d);
        tail = n;
        n->next = n;
        // cout << "op" << endl;
    }
    // non empty list
    else
    {
        node *curr = tail;
        while (element != curr->data)
        {
            curr = curr->next;
        }
        // curr points to node with element as data

        node *n = new node(d);
        n->next = curr->next;
        curr->next = n;
        // cout << "OP" << endl;
    }
}

void print(node *&tail)
{
    if (tail == NULL)
    {
        cout << "khali h bhai" << endl;
        return;
    }
    node *temp = tail;
    do // never knew i am going to use do... while
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

void deletion(node *&tail, int value)
{
    // null list
    if (tail == NULL)
    {
        cout << "empty h bhau" << endl;
        return;
    }

    // non empty and assuming the value is present in the list
    node *prev = tail;
    node *curr = tail->next;
    while (value != curr->data)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev == curr)
    {
        cout << "only one node" << endl;
        tail = NULL;
    }
    prev->next = curr->next;
    if (tail == curr)
    {
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
}

int main()
{
    node *tail = NULL;
    deletion(tail, 0);
    Insert(tail, 5, 369);
    // deletion(tail, 369);
    Insert(tail, 369, 9);
    // deletion(tail, 9);
    Insert(tail, 9, 36);
    Insert(tail, 9, 3);
    Insert(tail, 9, 6);
    print(tail);
    deletion(tail, 9);
    print(tail);
};