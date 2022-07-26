//find depth of given node
int helper(TreeNode<int>* root,TreeNode<int>* node,int d){
    if(root->val==node->val)
        return d;
    for(int i=0;i<root->children.size();i++)
    {
        int childh=getHeight(root->children[i],node,d+1);
    }
    return -1;
}
int getDepthofGivenNode(TreeNode<int>* root,TreeNode<int>* node) {
    return helper(root,node,0);
}