/*
Given a binary tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the binary tree.
Sample Input 1:

5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 10

Sample Output 1:

10

Sample Input 2:

5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 6

Sample Output 2:

5

*/
//Time O(N)
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    if(root==nullptr)
    return -1;
    if(root->data==a||root->data==b)
       return root->data;
    int n1=getLCA(root->left,a,b);
    int n2=getLCA(root->right,a,b);
    if(n1==-1 and n2==-1)
    return -1;
    else if(n1==-1)
    return n2;
    else if(n2==-2)
    return n1;
    else
    return root->data;
}