/*
Check whether given tree is balanced  or not
*/
#include<bits/stdc++.h>
#include <cstdlib>
pair<int,bool> helper(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        pair<int,bool> p;
        p.first=0;
        p.second=true;
        return p;
    }
    pair<int,bool> left=helper(root->left);
    pair<int,bool> right=helper(root->right);
    pair<int,bool> ans;
    if(abs(left.first-right.first)>1||!left.second||!right.second)
        ans.second=false;
    else
        ans.second=true;
    ans.first=1+max(left.first,right.first);
    return ans;
}
bool isBalanced(BinaryTreeNode<int> *root) {
   return helper(root).second;
}
//O(N) && SPACE-O(H)