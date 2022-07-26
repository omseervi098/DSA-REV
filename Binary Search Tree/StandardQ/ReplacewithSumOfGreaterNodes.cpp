/*
Given a binary search tree, you have to replace each node's data with the sum of all nodes which are greater or equal than it. You need to include the current node's data also.
That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.
Note: You don't need to return or print, just change the data of each node.
Sample Input 1 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

Sample Output 1 :
18 
36 10 
38 31 
25 
*/
//Time O(N)
//space O(H)
int helper(BinaryTreeNode<int> *root,int sum)
{
    if(root==NULL)
        return 0;
    int rightsum=helper(root->right,sum);
    int ans=root->data+rightsum+sum;
    root->data=ans;
    int leftsum=helper(root->left,ans);
    return ans-sum+leftsum;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
    int k=helper(root,0);
    
}