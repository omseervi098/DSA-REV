/*
For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Sample Input 1:
7
1 2 4 5 3 6 7 --> preorder
4 2 5 1 6 3 7 --> inorder

Sample Output 1:
1 
2 3 
4 5 6 7 

*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, int pres,int pree,vector<int>& in,int ins,int ine) {
        if(pres>pree ||ins>ine)
            return NULL;
        int prels,prele,prers,prere,inls,inle,inrs,inre;
        int i=pres;
        for(i=ins;i<ine;i++){
            if(in[i]==pre[pres])
                break;
        }
        inls=ins;
        inle=i-1;
        inrs=i+1;
        inre=ine;
        prels=pres+1;
        prele=(inle-inls)+prels;
        prers=prele+1;
        prere=pree;
        TreeNode* root=new TreeNode(pre[pres]);
        root->left=buildTree(pre,prels,prele,in,inls,inle);
        root->right=buildTree(pre,prers,prere,in,inrs,inre);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};
