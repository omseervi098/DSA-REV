/*
Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
Note: If array size is even, take first mid as root.
Sample Input 1:

7
1 2 3 4 5 6 7

Sample Output 1:

4 2 1 3 6 5 7 
*/
//time o(n)
BinaryTreeNode<int>* helper(int* arr,int si,int end)
{
    if(si>end)
    {
        return NULL;
    }
    int mid=(si+end)/2;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(arr[mid]);
    BinaryTreeNode<int>* lchild=helper(arr,si,mid-1);
    BinaryTreeNode<int>* rchild=helper(arr,mid+1,end);
    root->left=lchild;
    root->right=rchild;
    return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code herE
    return helper(input,0,n-1);
}