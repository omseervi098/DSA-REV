/*Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0

Sample Output 1 :
1

*///time o(n^2)
TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    TreeNode<int>* node=root;
    int sum=root->data;
    for(auto it:root->children)
        sum+=it->data;
    for(auto it:root->children){
        TreeNode<int>* child=maxSumNode(it);
        int ssum=child->data;
        for(auto i:child->children)
            ssum+=i->data;
        if(ssum>sum){
            sum=ssum;
            node=child;
         }
    }
    return node;
}
//optimised
//we can use pair to store node and its sum simultanously
//time o(n)
#include<bits/stdc++.h>
pair<TreeNode<int>*,int> helper(TreeNode<int>*root){
    pair<TreeNode<int>*,int> p1;
    p1.first=root;
    int sum=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        sum+=root->children[i]->data;
    }
    p1.second=sum;
    for(int i=0;i<root->children.size();i++){
        pair<TreeNode<int>*,int> sans=helper(root->children[i]);
        if(sans.second>p1.second)
        {
            p1.second=sans.second;
            p1.first=sans.first;
        }
    }
    return p1;
}
TreeNode<int>* maxSumNode(TreeNode<int> *root){
    return helper(root).first;
}