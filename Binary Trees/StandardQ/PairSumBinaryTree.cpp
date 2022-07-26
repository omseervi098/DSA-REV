/*
 Pair Sum Binary Tree
Send Feedback
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Note:

1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
Sample Input 1:

5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15

Sample Output 1:

5 10
6 9
*/
//Time O(N)
void inorder(vector<int> &ans,BinaryTreeNode<int>* root){
    if(root!=NULL){
        inorder(ans,root->left);
        ans.push_back(root);
        inorder(ans,root->right);
    }
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    vector<int> v;
    inorder(v,root);
    sort(v.begin(),v.end());
    int l = 0;
    int r = v.size() - 1;
    while (l < r) {
        if (v[l] + v[r] == sum){
            cout<<v[l]<<" "<<v[r]<<endl;
            l++;r--;
        }
        else if (v[l] + v[r] < sum)
            l++;
        else 
            r--;
    }
}