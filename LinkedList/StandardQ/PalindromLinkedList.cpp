/*
 Palindrome LinkedList

You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
Sample Input 1 :

1
9 2 3 3 2 9 -1

Sample Output 1 :

true

Sample Input 2 :

2
0 2 3 2 5 -1
-1

Sample Output 2 :

false
true



TAKES O(N) TIME
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
}Node *reverse(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *newhead=reverse(head->next);
    newhead->next=head;
    head->next=NULL;
    return newhead;
}
bool isPalindrome(Node *head)
{
    //Write your code here
    if(head==NULL)
        return true;
    bool check=true;
    int l=len(head);
    int mid=(l-1)/2;
    int i=0;
    Node* p=head,*p1=head;
    while(i<=mid-1)
    {
        p=p->next;i++;
    }
    Node* p2=reverse(p->next);
    p->next=NULL;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data!=p2->data)
        {
            check=false;
            break;
        }
        p1=p1->next;
        p2=p2->next;
    }
    return check;
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

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}