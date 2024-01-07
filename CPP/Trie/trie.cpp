#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void InsertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            // present
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        InsertUtil(child, word.substr(1));
    }
    void InsertWord(string word)
    {
        InsertUtil(root, word);
    }

    bool SearchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        // present
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            return false;
        }
        // recursion
        return SearchUtil(child, word.substr(1));
    }

    bool search(string word)
    {
        return SearchUtil(root, word);
    }
    bool isEmpty(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
            if (root->children[i])
                return false;

        return true;
    }

    TrieNode *deleteUtil(TrieNode *root, string word)
    {
        if (root == NULL)
            return NULL;

        // Last character being processed
        if (word.length() == 0)
        {
            // This will not be a word after removal
            if (root->isTerminal)
                root->isTerminal = false;

            // If this is not a prefix of any other word. [not helping to make any other word]
            if (isEmpty(root))
            {
                delete root;
                root = NULL;
            }

            return root;
        }

        // Recursion call
        int index = word[0] - 'a';
        root->children[index] = deleteUtil(root->children[index], word.substr(1));

        // Backtracking
        // If root has no child (as it's only child got deleted) and it is also not end of any other word
        if (isEmpty(root) && root->isTerminal == false)
        {
            delete root;
            root = NULL;
        }

        return root;
    }

    TrieNode *deleteWord(string word)
    {
        return deleteUtil(root, word);
    }
};

int main()
{

    Trie *t = new Trie();

    t->InsertWord("abcde");
    t->InsertWord("abe");
    t->InsertWord("abcd");
    cout << "present or Not " << t->search("abcde") << endl;
    t->deleteWord("abcde");
    cout << "present or Not " << t->search("abcde") << endl;
    return 0;
}