#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    // since it points to address of a node then node*
    node *next;
    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // ~node()
    // {
    //     int value = this->data;
    //     if (this->next != NULL)
    //     {
    //         this->next = NULL;
    //         delete this->next;
    //             }
    //     cout << "memory free of data " << value << endl;
    // }
};

void InsertatHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head; // replace head by tail->next=temp
    head = temp;       // tail=temp
}
void InsertatTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void InsertatMiddle(node *&tail, node *&head, int position, int d)
{
    node *newnode = new node(d);
    int cnt = 1;
    node *temp = head;
    if (position == 1)
    {
        InsertatHead(head, d);
        return;
    }
    while (cnt < position - 1)
    {
        cnt++;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        InsertatTail(tail, d);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletion(node *&head, node *&tail, int position)
{
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        // memory free
        // temp->next = NULL;
        delete temp;
    }
    else
    {
        node *curr = head;
        node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            tail = prev;
        }
        prev->next = curr->next;
        // curr->next = NULL;
        delete curr;
    }
}

void print(node *&head)
{
    node *temp = head; // to avoid making changes in original linked list
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *n1 = new node(10);
    // cout << n1->data << endl;
    // cout << n1->next << endl;
    node *head = n1;
    node *tail = n1;
    print(head);
    InsertatHead(head, 12);
    print(head);
    InsertatTail(tail, 15);
    print(head);
    InsertatMiddle(tail, head, 4, 22); // change positions
    print(head);
    deletion(head, tail, 4);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
};