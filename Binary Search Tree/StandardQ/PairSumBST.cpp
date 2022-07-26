/*
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12

Sample Output 1:
2 10
5 7
*/
//TIME O(N) and SPACE O(N)
#include<bits/stdc++.h>
void helper(BinaryTreeNode<int> *root,vector<int>& v)
{
    if(root==NULL)
        return;
    helper(root->left,v);
    v.push_back(root->data);
    helper(root->right,v);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    vector<int>v;
    helper(root,v);
    int l=0;
    int r=v.size()-1;
    while(l<r)
    {
        if(v[l]+v[r]==s)
        {
            cout<<v[l]<<" "<<v[r]<<endl;
            l++;r--;
        }else if(v[l]+v[r]<s)
        {
            l++;
        }else
            r--;
    }
//We can optimise space to O(H) *H is height of tree
//by using two stacks
int countnodes(BinaryTreeNode<int> *root)
{
    if(root==NULL)
        return 0;
    return 1+countnodes(root->left)+countnodes(root->right);
}
void printNodesSumToS(BinaryTreeNode<int> *root,int s){
    if(root==nullptr)return;
    int count=countnodes(root);
    int k=0;
    stack<BinaryTreeNode<int>*> inorder;
    stack<BinaryTreeNode<int>*> revinorder;
    BinaryTreeNode<int>* curr=root;
    while(curr!=nullptr)
    {
        inorder.push(curr);
        curr=curr->left;
    }
    curr=root;
    while(curr!=nullptr)
    {
        revinorder.push(curr);
        curr=curr->right;
    }
    while(k<count-1){
        BinaryTreeNode<int>* inordertop=inorder.top();
        BinaryTreeNode<int>* revinordertop=revinorder.top();
        if(inordertop->data+revinordertop->data==s){
            cout<<inordertop->data<<" "<<revinorder->top->data<<endl;
            BinaryTreeNode<int>* top=inordertop;
            inorder.pop();k++;
            if(top->right!=nullptr){
                top=top->right;
                while(top!=nullptr)
                {
                    inorder.push(top);
                    top=top->left;
                }
            }
            top=revinordertop;
            revinorder.pop();
            k++;
            if(top->left!=NULL){
                top=top->left;
                while(top!=NULL)
                {
                    revinorder.push(top);
                    top=top->right;
                }
            }
        }else if(inordertop->data+revinordertop->data<s){
            BinaryTreeNode<int>* top=inordertop;
            inorder.pop();k++;
            if(top->right!=nullptr){
                top=top->right;
                while(top!=nullptr)
                {
                    inorder.push(top);
                    top=top->left;
                }
            }
        }else{
            BinaryTreeNode<int>* top=revinordertop;
            revinorder.pop();k++;
            if(top->left!=NULL){
                top=top->left;
                while(top!=NULL)
                {
                    revinorder.push(top);
                    top=top->right;
                }
            }
        }
    }
}