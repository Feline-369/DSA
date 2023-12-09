#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node
{
public:
    int data;

    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *minval(node *root)
{
    if (root == NULL)
    {
        return root;
    }
    while (root->left)
    {
        root = root->left;
    }
    return root;
}
node *deleteFromBST(node *root, int del)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == del)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return NULL;
        }
        if (root->left != NULL && root->right != NULL)
        {
            int mini = (minval(root->right))->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > del)
    {
        root->left = deleteFromBST(root->left, del);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, del);
        return root;
    }
}
node *insert(node *&root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insert(root->right, d);
    }
    else
    {
        root->left = insert(root->left, d);
    }
    return root;
}
void input(node *&root)
{
    int data;
    cin >> data;
    while (data != 0)
    {
        insert(root, data);
        cin >> data;
    }
}

void traversal(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    traversal(root->left);
    cout << root->data << endl;
    traversal(root->right);
}

int main()
{
    node *root = NULL;
    cout << "Enter data : " << endl;
    input(root);
    cout << " Traversal : " << endl;
    traversal(root);
    cout << "Deleting item: " << endl;
    int del;
    cin >> del;
    root = deleteFromBST(root, del);
    cout << "deleted" << endl;
    traversal(root);
}