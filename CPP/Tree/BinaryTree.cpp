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

void LevelOrderTransversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    // create tree
    node *root;
    root = buildTree(root);
    cout << "printing level order transversal" << endl;
    LevelOrderTransversal(root);
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
};
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 3 6 36 93 -1 -1 -1 39 -1 -1 9 69 96 -1 -1  -1 63 -1 -1