/*
Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Sample Input 1:

8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

Sample Output 1:

2 5 6 7 8 10
*/
//time o(n)
#include<bits/stdc++.h>
pair<Node<int>*,Node<int>*> helper(TreeNode* root){
    if(root==NULL)
    {
        pair<Node<int>*,Node<int>*> p;
        p.first=NULL;
        p.second=NULL;
        return p;
    }
    pair<Node<int>*,Node<int>*> lchild=helper(root->left);
    pair<Node<int>*,Node<int>*> rchild=helper(root->right);
    Node<int>* newNode=new 	Node<int>(root->data);
     pair<Node<int>*,Node<int>*>p1;
         
    if(lchild.first==NULL && rchild.first==NULL)
    {
        p1.first=newNode;
        p1.second=newNode;
    }
    else if(lchild.first==NULL)
    {
        p1.first=newNode;
        newNode->next=rchild.first;
        p1.second=rchild.second;
    }
    else if(rchild.first==NULL)
    {
        lchild.second->next=newNode;
        p1.first=lchild.first;
        p1.second=newNode;
    }
    else
    {
        p1.first=lchild.first;
        lchild.second->next=newNode;
        newNode->next=rchild.first;
        p1.second=rchild.second;
    }
    return p1;
}
Node<int>* constructLinkedList(TreeNode* root) {
	// Write your code here
    return helper(root).first;
}