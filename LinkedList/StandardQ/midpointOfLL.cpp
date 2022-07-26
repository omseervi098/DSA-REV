/*find and return midpoint of linked list*/
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
//THIS APProach with finding length of linked list is amazing useful
//takes o(n) time
Node *midPoint(Node *head)
{
    // Write your code here
    if(head==NULL||head->next==NULL)
        return head;
    Node* slow=head,*fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    
}