/*
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1 :
40
*/
// dfs
// in this first is our maximum and and second second max
void secondLargestUtil(Node *root, Node **first,
                       Node **second)
{
    if (root == NULL)
        return;

    // If first is NULL, make root equal to first
    if (!(*first))
        *first = root;

    // if root is greater than first then second
    // will become first and update first equal
    // to root
    else if (root->key > (*first)->key)
    {
        *second = *first;
        *first = root;
    }

    // If root is less than first but greater than
    // second
    else if (!(*second) || root->key > (*second)->key)
        *second = root;

    // number of children of root
    int numChildren = root->child.size();

    // recursively calling for every child
    for (int i = 0; i < numChildren; i++)
        secondLargestUtil(root->child[i], first, second);
}

//bfs
#include<bits/stdc++.h>
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here=
    queue<TreeNode<int>*> q;
    TreeNode<int>* max=root;
    TreeNode<int>*smax=NULL;
    q.push(root);
    while (q.size() != 0){
        TreeNode<int>* front = q.front();
        q.pop();
        for(int i=0;i<(front->children.size());i++)
        {
            q.push(front->children[i]);
            if(smax==NULL && front->children[i]->data<max->data)
                smax=front->children[i];
            if(front->children[i]->data>max->data)
            {
                smax=max;
                max=front->children[i];
            }else if(smax!=NULL&&front->children[i]->data>smax->data && front->children[i]->data<max->data)
            {
                smax=front->children[i];
            }
        }
    }
    return smax;
}
//DFS using pairs
pair<TreeNode<int>*,TreeNode<int>*> helper(TreeNode<int>* root){
    if(root==nullptr){
        return {nullptr,nullptr};
    }
    pair<TreeNode<int>*,TreeNode<int>*> ans(root,nullptr);
    for(auto it:root->children){
        pair<TreeNode<int>*,TreeNode<int>*>child=helper(it);
        if(child.first->data>ans.first->data){
            if(child.second==nullptr){
                ans.second=ans.first;
                ans.first=child.first;
            }else {
                if(child.second->data>ans.first->data){
                    ans.second=child.second;
                    ans.first=child.first;
                }else{
                    ans.second=ans.first;
                    ans.first=child.first;
                }
            }
        }else if(ans.first->data!=child.first->data and( ans.second==nullptr ||child.first->data>ans.second->data)){
            ans.second=child.first;
        }
     }return ans;
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
     return helper(root).second;
}