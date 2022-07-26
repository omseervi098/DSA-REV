//time o(n)
int sumOfNodes(TreeNode<int>* root) {
    int sum=root->data;
    for(auto it:root->children)
        sum+=sumOfNodes(it);
    return sum;
}