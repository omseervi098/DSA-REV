// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/

/*
Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two nodes are cousins of each other or not. Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.
Do it in O(n).
Sample Input :

5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
2
4

Sample Output :

true


*/
// time o(n)
int depthofgivennode(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
        return -1;
    if (root->data == data)
        return 0;
    int d1 = depthofgivennode(root->left, data);
    if (d1 != -1)
        return d1 + 1;
    else
    {
        int d2 = depthofgivennode(root->right, data);
        if (d2 != -1)
            return d2 + 1;
        else
            return -1;
    }
}
bool isnotsibling(BinaryTreeNode<int> *root, int p, int q)
{
    if (root == nullptr || (root->left == nullptr and root->right == nullptr))
        return true;
    if (root->left == nullptr)
    {
        return isnotsibling(root->right, p, q);
    }
    else if (root->right == nullptr)
        return isnotsibling(root->left, p, q);
    else
    {
        if (root->left->data == p and root->right->data == q)
            return false;
        else if (root->left->data == q and root->right->data == p)
            return false;
        return isnotsibling(root->left, p, q) and isnotsibling(root->right, p, q);
    }
}
bool isCousin(BinaryTreeNode<int> *root, int p, int q)
{
    if (root == nullptr)
        return false;
    return (depthofgivennode(root, p) == depthofgivennode(root, q) && isnotsibling(root, p, q));
}

//bfs approach
class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {

        if (root == NULL)
            return false;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            TreeNode*front = q.front();
            q.pop();
            if (front == NULL)
            {
                if (q.empty())
                    break;
                q.push(NULL);
                continue;
            }
            if(front->val==x or front->val==y){
                if(q.front()!=nullptr and (q.front()->val==x or q.front()->val==y))
                    return false;
            }
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }return true;
    }
};