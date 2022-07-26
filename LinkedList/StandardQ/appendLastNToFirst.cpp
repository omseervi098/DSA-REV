/*
AppendLastNToFirst

You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.

Sample Input 1 :

2
1 2 3 4 5 -1
3
10 20 30 40 50 60 -1
5

Sample Output 1 :

3 4 5 1 2
20 30 40 50 60 10

*/
#include <iostream>

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

using namespace std;
int len(Node* head)
{
    Node* p=head;
    int l=0;
    while(p!=NULL)
    {
        l++;
        p=p->next;
    }
    return l;
}//time o(n)
Node *appendLastNToFirst(Node *head, int n)
{
    if(n==0 || head==NULL)return head;
    int l=len(head);
    n=n%l;
    int firstn=len(head)-n;
    Node* p=head;
    while(p->next!=nullptr and (firstn--)>1){
        p=p->next;
    }
    Node* lastnhead=p->next;
    Node* ptr=lastnhead;
    while(ptr->next!=nullptr){
        ptr=ptr->next;
    }
    ptr->next=head;
    p->next=NULL;
    return lastnhead;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}
