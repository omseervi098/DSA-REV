/*
543. Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/
//Bruteforce
//o(n^2) time
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int op1=height(root->left)+height(root->right);
        int op2=diameterOfBinaryTree(root->left);
        int op3=diameterOfBinaryTree(root->right);
        return max(op1,max(op2,op3));
    }
};
//optimised time O(n)
class Solution {
public:
    pair<int,int> helper(TreeNode* root){
        
        if(root==NULL)
            return {0,0};
        pair<int,int> ans;
        pair<int,int> op2=helper(root->left);
        pair<int,int> op3=helper(root->right);
        ans.first=1+max(op2.first,op3.first);
        ans.second=max(op2.second,max(op3.second,(op2.first+op3.first)));
        return ans;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        return helper(root).second;
    }
};