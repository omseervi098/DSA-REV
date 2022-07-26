/*
Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
Note: Return NULL if no node is present with the value greater than n.

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
18
Sample Output 1 :
20
*/
//time o(n)
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    TreeNode<int>* node=nullptr;
    if(root->data>x){
        node=root;
    }
    for(auto it:root->children){
        TreeNode<int>* child=getNextLargerElement(it,x);
        if(child==nullptr and node==nullptr)
        return nullptr;
        else if(child==nullptr)
        return node;
        else if(node==nullptr)
        return child;
        else{
            if(child->data<node->data){
                node=child;
            }
        }
    }
    return node;
}
   