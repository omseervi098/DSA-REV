//Time o(n) 
//Pair {Min,Max} 
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL){
        pair<int,int>p2;
        p2.first=-1;
        p2.second=-1;
        return p2; 
    }
    pair<int,int> p;
    p.first=root->data;
    p.second=root->data;
    if(root->left){
    pair<int,int> left=getMinAndMax(root->left);
    if(left.first<p.first)
        p.first=left.first;
    if(p.second<left.second)
        p.second=left.second;}
    if(root->right){
    pair<int,int> right=getMinAndMax(root->right);
    if(right.first<p.first)
        p.first=right.first;
    if(p.second<right.second)
        p.second=right.second;
    }
    return p;
}
//there is one more approach to do this q is 
//by passing two variable min and max as paramter to function 
//ans then keep on updating them