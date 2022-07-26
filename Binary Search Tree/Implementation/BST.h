#include <bits/stdc++.h>
using namespace std;
template <typename T>
class node
{
public:
    T val;
    node<T> *left;
    node<T> *right;
    node(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
class BST
{
    node<int> *r;
    node<int> *takeinput(node<int> *root, int data)
    {
        if (root == nullptr)
        {
            node<int> *nnode = new node<int>(data);
            return nnode;
        }
        if (data >= root->val)
            root->right = takeinput(root->right, data);
        else
            root->left = takeinput(root->left, data);
        return root;
    }
    bool search(node<int> *root, int data)
    {
        if (root == nullptr)
            return false;
        if (root->val == data)
            return true;
        if (data >= root->val)
            return search(root->right, data);
        else
            return search(root->left, data);
    }
    void print(node<int> *root)
    {
        if (root == NULL)
            return;
        queue<node<int> *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            node<int> *currentNode = q.front();
            q.pop();
            if (currentNode == NULL)
            {
                cout << endl;
                if (!q.empty())
                    q.push(NULL);
                continue;
            }
            else
                cout << currentNode->val << " ";
            if (currentNode->left != NULL)
                q.push(currentNode->left);
            if (currentNode->right != NULL)
                q.push(currentNode->right);
        }
    }
    node<int> *deletenode(node<int> *root, int data)
    {
        if (root == nullptr)
            return nullptr;
        if (data > root->val)
            root->right = deletenode(root->right, data);
        else if (data < root->val)
            root->left = deletenode(root->left, data);
        else
        {
            if (root->left == nullptr and root->right == nullptr)
                return nullptr;
            else if (root->left == nullptr)
                return root->right;
            else if (root->right == nullptr)
                return root->left;
            else
            {
                node<int> *minnode = root->right;
                while (minnode->left != nullptr)
                    minnode = minnode->left;
                swap(minnode->val, root->val);
                return root;
            }
        }
        return root;
    }

public:
    void takeinput(int data)
    {
        r = takeinput(r, data);
    }
    void deletenode(int data)
    {
        r = deletenode(r, data);
    }
    bool search(int data)
    {
        return search(r, data);
    }
    void print()
    {
        print(r);
    }
};