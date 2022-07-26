/*
Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output :
5
10 6
2 3
9
*/
#include <bits/stdc++.h>
//bfs approach time o(n) and space o(n)
void zigZagOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    bool forward=true;
    vector<vector<int>> fans;
    vector<int>ans;
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentBinaryTreeNode=q.front();q.pop();
        if (currentBinaryTreeNode == NULL)
        {
            if(!forward)
                reverse(ans.begin(),ans.end());
            fans.push_back(ans);
            ans.clear();
            forward=!forward;
            if (q.empty())
               break;
            q.push(NULL);
            continue;
        }
        else
            ans.push_back(currentBinaryTreeNode->data);
        if (currentBinaryTreeNode->left != NULL )
            q.push(currentBinaryTreeNode->left);
        if (currentBinaryTreeNode->right != NULL )
            q.push(currentBinaryTreeNode->right);
        
    }
    for(int i=0;i<fans.size();i++)
    {
        for(int j=0;j<fans[i].size();j++){
            cout<<fans[i][j]<<" ";
        }
        cout<<endl;
    }
}
//dfs approach
//time o(n^2)
int height(BinaryTreeNode<int>* root){
    if(root==nullptr){
        return 0;
    }return 1+max(height(root->left),height(root->right));
}
void helper(int h,BinaryTreeNode<int> * root,bool forward){
    if(root==nullptr)
    return ;
    if(h==1)
    cout<<root->data<<" ";
    if(forward){
        helper(h-1,root->left,forward);
        helper(h-1,root->right,forward);
    }else{
        helper(h-1,root->right,forward);
        helper(h-1,root->left,forward);
    }

}
void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    int h=height(root);
    bool check=true;
    for(int i=1;i<=h+1;i++){
       helper(h,root,check);
       cout<<endl;
       check=!check;
    }
}
//better dfs approach 
//takes o(n) time
#include <bits/stdc++.h>
void zigZagOrder(BinaryTreeNode<int> *root) {
    stack<BinaryTreeNode<int> *> s;     //for even level
    stack<BinaryTreeNode<int> *> s1;    //For odd level
    s.push(root);
    bool flag=true;
    int cnt=1;
    int level=0;
    while(!s.empty() ||!s1.empty()){
        if(flag){
            BinaryTreeNode<int> *currentBinaryTreeNode=s.top();s.pop();
            cout<<currentBinaryTreeNode->data<<" ";
            cnt--;
            if(currentBinaryTreeNode->left!=NULL){
                s1.push(currentBinaryTreeNode->left);level++;}
            if(currentBinaryTreeNode->right!=NULL){
                s1.push(currentBinaryTreeNode->right);level++;}
            if(cnt==0){
                cout<<endl;
                cnt=level;
                flag=false;
                level=0;
            }

        }else{
            BinaryTreeNode<int> *currentBinaryTreeNode=s1.top();s1.pop();
            cout<<currentBinaryTreeNode->data<<" ";
            cnt--;
            if(currentBinaryTreeNode->right!=NULL){
                s.push(currentBinaryTreeNode->right);level++;}
            if(currentBinaryTreeNode->left!=NULL){
                s.push(currentBinaryTreeNode->left);level++;}
            if(cnt==0){
                cout<<endl;
                cnt=level;
                flag=true;
                level=0;
            }
        }
    }
}