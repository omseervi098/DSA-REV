/**
You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.
Sample Input 1 :

1
2 5 8 12 -1
3 6 9 -1

Sample Output 1 :

2 3 5 6 8 9 12 

**/
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
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //o(n+m) time o(1)space
    Node*fh=NULL,*ft=NULL,*h1=head1,*h2=head2;
    if(h1==NULL)
        return h2;
    if(h2==NULL)
        return h1;
    if(h1->data<h2->data)
    {
        fh=h1;
        ft=h1;
        h1=h1->next;
    }else
    {
        fh=h2;
        ft=h2;
        h2=h2->next;
    }
    while(h1!=NULL && h2!=NULL)
    {
        if(h2->data<=h1->data)
        {
            ft->next=h2;
            ft=ft->next;
            h2=h2->next;
        }else
        {
            ft->next=h1;
            ft=ft->next;
            h1=h1->next;
        }
    }
    if(h1!=NULL)
    {
        ft->next=h1;
    }else
        ft->next=h2;
   
    return fh;
}