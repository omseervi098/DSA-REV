/*
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Sample Input 1:

5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1:

5 
6 10 
2 3 
9

*/
//time o(n) space o(n)
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    vector<Node<int>*> arr;
    if(root==NULL)
    {
        arr.push_back(NULL);
        return arr;
    }
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    q.push(NULL);
    Node<int>* tail=NULL;
    Node<int>* head=NULL;
    while(q.size()!=0)
    {
        BinaryTreeNode<int> *front=q.front();
        q.pop();
        if(front!=NULL)
        {   //create newnode with front->data
            Node<int>* temp=new Node<int>(front->data);
            if(tail==NULL)
            {
                head=temp;
                tail=temp;
            }else
            {
                tail->next=temp;
                tail=tail->next;
            }
        }else
        {
            arr.push_back(head);
            tail=NULL;
            if(q.empty())
                break;
            q.push(NULL);
            continue;
        }
        if(front->left!=NULL)
            q.push(front->left);
        if(front->right!=NULL)
            q.push(front->right);
    }
    return arr;
}
