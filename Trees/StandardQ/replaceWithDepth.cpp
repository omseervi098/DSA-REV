/*
You are given a generic tree. You have to replace each node with its depth value. You just have to update the data of each node, there is no need to return or print anything.
Sample Input 1:

10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output 1:

0 
1 1 1 
2 2


*/
void helper(TreeNode<int>* root,int d){
    root->val=d;
    for(auto it:root->children){
        helper(it,d+1);
    }
}
void replaceWithDepthValue(TreeNode<int>* root) {
    helper(root,0);
}