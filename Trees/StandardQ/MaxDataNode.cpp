/*
Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.
Return null if tree is empty.
*/
//time o(n)
#include<bits/stdc++.h>
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    TreeNode<int>* mx=root;
    for(auto it:root->children){
        TreeNode<int>* k=maxDataNode(it);
        if(k->data>mx->data)
           mx=k;
    }return mx;
}