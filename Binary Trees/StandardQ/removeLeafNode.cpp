/*
Given a binary tree, remove all leaf nodes from it. Leaf nodes are those nodes, which don't have any children.
Note:

1. Root will also be a leaf node if it doesn't have left and right child. 
2. You don't need to print the tree, just remove all leaf nodes and return the updated root.
Sample Input 1:

8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

Sample Output 1:

8
3 10
6 14                    


*/
//time o(n) 
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if(root==nullptr or (root->left==nullptr and root->right==nullptr)){
        return nullptr;
    }
    root->left=removeLeafNodes(root->left);
    root->right=removeLeafNodes(root->right);
    return root;
}