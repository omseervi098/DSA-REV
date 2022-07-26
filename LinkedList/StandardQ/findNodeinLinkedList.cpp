/*
You have been given a singly linked list of integers. Write a function that returns the index/position of integer data denoted by 'N' (if it exists). Return -1 otherwise.
Sample Input 1 :

2
3 4 5 2 6 1 9 -1
5
10 20 30 40 50 60 70 -1
6

Sample Output 1 :

2
-1

*/
//time o(n)
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
int findNode(Node *head, int n){
    
    Node* p=head;
    int len=0;
    while(p!=NULL)
    {
        if(p->data==n)
        {
           break;
        }else
        {
            len++;
            p=p->next;
        }
    }
    if(p==NULL)
        return -1;
    return len;
}
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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
		int val;
		cin >> val;
		cout << findNode(head, val) << endl;
	}
}