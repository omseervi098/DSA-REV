/*
Given a binary search tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the BST.
LCA

LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 
Sample Input 1:

8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 10

Sample Output 1:

8

Sample Input 2:

8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 6

Sample Output 2:

5

Sample Input 3:

8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12 78

Sample Output 3:

-1


*/
//time --O(H) and space O(H)
int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    if(root==nullptr)return -1;
    if(root->data==val1||root->data==val2)
    return root->data;
    if(root->data>val1 and root->data>val2)
        return getLCA(root->left,val1,val2);
    else if(root->data<v1 and root->data<val2)
        return getLCA(root->right,val1,val2);
    return root;
}