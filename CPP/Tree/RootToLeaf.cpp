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
node *buildTree(node *root)
{
    cout << "enter data" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "for left node of " << data << " ";
    root->left = buildTree(root->left);
    cout << "enter data for right node of " << data << "  ";
    root->right = buildTree(root->right);

    return root;
}
void inorder(node *root, int &sum)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, sum);
    sum += root->data;
    inorder(root->right, sum);
}
int main()
{
    // create tree
    node *root;
    int sum = 0;
    root = buildTree(root);
    inorder(root, sum);
    cout << sum << endl;
};