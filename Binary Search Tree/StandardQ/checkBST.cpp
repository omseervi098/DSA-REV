/*
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.
Sample Input 1 :

3 1 5 -1 2 -1 -1 -1 -1

Sample Output 1 :

true

Sample Input 2 :

5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1

Sample Output 2 :

false
*/
//BruteForce --O(N^2)
#include<bits/stdc++.h>
int maximum(BinaryTreeNode<int> *root){
    if(root==NULL)
        return INT_MIN;
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
int minimum(BinaryTreeNode<int> *root)
{
    if(root==NULL)
        return INT_MAX;
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root) {
    if(root==NULL||root->left==NULL &&root->right==NULL)
        return true;
    int lmax=maximum(root->left);
    int rmin=minimum(root->right);
    if(root->data>lmax &&root->data<=rmin)
        return true;
    return isBST(root->left)&&isBST(root->right)&&root->data>lmax &&root->data<=rmin;
}
//Optimised --O(N)
class IsBSTReturn {
	public:
		bool isBST;
		int minimum;
		int maximum;
};

IsBSTReturn isBST2(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		IsBSTReturn output;
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}
	IsBSTReturn leftOutput = isBST2(root->left);
	IsBSTReturn rightOutput = isBST2(root->right);
	int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
	int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
	bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) &&
		leftOutput.isBST && rightOutput.isBST;
	IsBSTReturn output;
	output.minimum = minimum;
	output.maximum = maximum;
	output.isBST = isBSTFinal;
	return output;
}
//another approach -- O(N)
bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX) {
	if (root == NULL) {
		return true;
	}
	if (root->data < min || root->data > max) {
		return false;
	}
	bool isLeftOk = isBST3(root->left, min, root->data - 1);
	bool isRightOk = isBST3(root->right, root->data, max);
	return isLeftOk && isRightOk;
}