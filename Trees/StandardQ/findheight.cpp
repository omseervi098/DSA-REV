//find height of given tree
//time o(n)
int getHeight(TreeNode<int>* root) {
    int h=-1;
    for(int i=0;i<root->children.size();i++)
    {
        int childh=getHeight(root->children[i]);
        h=max(h,childh);
    }
    return h+1;
}