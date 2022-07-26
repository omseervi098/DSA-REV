/*
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2
*/
//Given binary tree we need to find largestbst so we everytime we need to check whether it is bst or not and also we need to maintain height of MaxBST
//for that either we can individual function for that like
//"ISBST" which will check whether it is bst or not
//if it is bst than we update height else we take max 
//But in this approach it will take o(n^2) time 
//So instead of that we maintain class consist (max,min,isbst,height)
//This will take O(N) time 
class isBST{
    public:
    bool BST;
    int rmin;
    int lmax;
    int height;
};
#include<bits/stdc++.h>
isBST helper(BinaryTreeNode<int>*root){
    if(root==NULL)
    {
        isBST s1;
        s1.BST=true;
        s1.rmin=INT_MAX;
        s1.lmax=INT_MIN;
        s1.height=0;
        return s1;
    }
    isBST left=helper(root->left);
    isBST right=helper(root->right);
    isBST s2;
    s2.rmin=min(root->data,min(left.rmin,right.rmin));
    s2.lmax=max(root->data,max(left.lmax,right.lmax));
    s2.BST=(left.BST)&&(right.BST)&&(root->data<=right.rmin)&&(root->data>left.lmax);
    
    if(s2.BST)
    {
        s2.height=1+max(left.height,right.height);
        return s2;
    }else
    {
        s2.height=max(left.height,right.height);
        return s2;
    }
}
    
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    isBST s3=helper(root);
    return s3.height;
}