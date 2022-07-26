/*
Given two generic trees, return true if they are structurally identical. Otherwise return false.
Structural Identical 
If the two given trees are made of nodes with the same values and the nodes are arranged in the same way, then the trees are called identical. 
*/
//time o(n)
bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1->data!=root2->data||root1->children.size()!=root2->children.size())
        return false;
    for(auto it:root1->children){
        bool check=areIdentical(it,it);
        if(!check)
            return false;
    }
    return true;
}