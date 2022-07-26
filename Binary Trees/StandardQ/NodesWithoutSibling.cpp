/*
For a given Binary Tree of type integer, print all the nodes without any siblings.
Input Format:

The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Sample Input 1:

5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1:

9    

Sample Input 2:

2 4 5 6 -1 -1 7 20 30 80 90 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 2:

6 7  
*/
void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root==nullptr||(root->left==nullptr && root->right==nullptr))
        return;
    if(root->left==nullptr){
        cout<<root->right->data<<" ";
    }else if(root->right==nullptr)
        cout<<root->left->data<<" ";
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}