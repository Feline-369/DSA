#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node
{
public:
    int data;

    node *prev;
    node *next;

    node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int len(node *&head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(node *&head, int d)
{
    node *n = new node(d);
    head->prev = n;
    n->next = head;
    head = n;
}

void insertAtTail(node *&tail, int d)
{
    node *n = new node(d);
    tail->next = n;
    n->prev = tail;
    tail = n;
}

void InsertatPosition(node *&tail, node *&head, int position, int d)
{
    node *newnode = new node(d);
    int cnt = 1;
    node *temp = head;
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    while (cnt < position - 1)
    {
        cnt++;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    newnode->next = temp->next;
    temp->next->prev = newnode;
    newnode->prev = temp;
    temp->next = newnode;
}

void deletion(node *&head, node *&tail, int position)
{
    int l = len(head);
    cout << "Length" << l << endl;
    if (position == l)
    {
        tail = tail->prev;
    }
    if (position == 1)
    {
        node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;

        delete temp;
    }
    else
    {
        node *curr = head;
        int cnt = 1;
        while (cnt < position)
        {
            curr = curr->next;
            cnt++;
        }
        curr->prev->next = curr->next;
        curr->prev = NULL;
        if (position != l)
        {
            curr->next->prev = curr->prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    node *head = new node(3);
    node *tail = head;
    // print(head);
    // cout << len(head) << endl;
    insertAtHead(head, 6);
    insertAtHead(head, 9);
    insertAtTail(tail, 36);
    // insertAtTail(tail, 96);
    // insertAtTail(tail, 69);
    InsertatPosition(tail, head, 4, 69);
    print(head);
    // cout << head->data << endl;
    // cout << tail->data << endl;
    deletion(head, tail, 5);
    print(head);
    // cout << head->data << endl;
    cout << "tail" << tail->data << endl;
};