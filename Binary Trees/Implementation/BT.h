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
class BinaryTree
{
    node<int> *root;

private:
    node<int> *takeinputa()
    {
        cout << "Enter root value: ";
        int data;
        cin >> data;
        if (data == -1)
        {
            return NULL;
        }
        node<int> *newnode = new node<int>(data);
        newnode->left = takeinputa();
        newnode->right = takeinputa();
        return newnode;
    }
    node<int> *takeinputbetter()
    {
        int rootData;

        cin >> rootData;
        if (rootData == -1)
        {
            return NULL;
        }
        node<int> *root = new node<int>(rootData);
        queue<node<int> *> q;
        q.push(root);
        while (!q.empty())
        {
            node<int> *currentNode = q.front();
            q.pop();
            int leftChild, rightChild;

            cin >> leftChild;
            if (leftChild != -1)
            {
                node<int> *leftNode = new node<int>(leftChild);
                currentNode->left = leftNode;
                q.push(leftNode);
            }

            cin >> rightChild;
            if (rightChild != -1)
            {
                node<int> *rightNode =
                    new node<int>(rightChild);
                currentNode->right = rightNode;
                q.push(rightNode);
            }
        }return root;
    }

public:
    void takeinput()
    {
        root = takeinputbetter();
    }

private:
    void print(node<int> *node)
    {
        if (node == NULL)
            return;
        cout << node->val << " ";
        print(node->left);
        print(node->right);
    }
    void postorder(node<int> *node)
    {
        if (node == NULL)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->val << " ";
    }
    void inorder(node<int>*node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }
    void printlevelwise(node<int> *root){
        if(root == NULL)
            return;
        queue<node<int>*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            node<int> *currentNode = q.front();
            q.pop();
            if(currentNode == NULL){
                cout<<endl;
                if(!q.empty())
                    q.push(NULL);
                continue;
            }else
               cout << currentNode->val << " ";
            if(currentNode->left != NULL)
                q.push(currentNode->left);
            if(currentNode->right != NULL)
                q.push(currentNode->right);
        }
    }
    int countNodes(node<int>* node){
        if(node == NULL)
            return 0;
        return 1+countNodes(node->left)+countNodes(node->right);
    }
    bool findnode(node<int>* node,int x){
        if(node == NULL)
            return false;
        if(node->val == x)
            return true;
        return findnode(node->left,x) || findnode(node->right,x);
    }
    int findheight(node<int>* node){
        if(node == NULL)
            return 0;
        return 1+max(findheight(node->left),findheight(node->right));
    }
    void mirror(node<int>* node){
        if(node == NULL)
            return;
        swap(node->left,node->right);
        mirror(node->left);
        mirror(node->right);
    }
public:
    void print()
    {
        cout<<"Preorder: ";
        print(root);
        cout<<"\nInorder: ";
        inorder(root);
        cout<<"\nPostorder: ";
        postorder(root);
        cout<<"\nLevelwise:\n";
        printlevelwise(root);
        cout<<endl;
    }
    int countNodes(){
        return countNodes(root);
    }
    bool findnode(int x){
        return findnode(root,x);
    }
    int findheight(){
        return findheight(root);
    }
    void mirror(){
        mirror(root);
    }

};