/*
Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.
Note: Assume that BST contains all unique elements.
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1:
2 5 8
*/
//Time O(H) but in worst case h=n then O(N)
vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	if(root==NULL)
        return nullptr;
    vector<int>* ans=new vector<int>();
    if(root->data==data){
        ans->push_back(data);
        return ans;
    }
    if(data>root->data){
        ans=getPath(root->right,data);
        if(ans==nullptr) return nullptr;
        ans->push_back(root->data);
    }else if(data<root->data){
        ans=getPath(root->left,data);
        if(ans==nullptr)return nullptr;
        ans->push_back(root->data);
        
    }
    return ans;
}