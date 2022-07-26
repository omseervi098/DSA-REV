/*
For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum of all the node data along the path is equal to K.
Sample Input 1:

2 3 9 4 8 -1 2 4 -1 -1 -1 6 -1 -1 -1 -1 -1
13

 Sample Output 1:

2 3 4 4 
2 3 8

*/
//Time O(N) and space O(N)
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k,vector<int>& ans){
    if(root==nullptr){
        return;
    }
    if(root->left==nullptr and root->right==nullptr){
        if(k==root->data){
            for(auto it:ans)
                cout<<it<<" ";
            cout<<root->data<<endl; 
        }
    }
    ans.push_back(root->data);
    rootToLeafPathsSumToK(root->left,k-root->data,ans);   
    rootToLeafPathsSumToK(root->right,k-root->data,ans);
    ans.pop_back();
    
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    vector<int> v;
    rootToLeafPathsSumToK(root,k,v);
}
