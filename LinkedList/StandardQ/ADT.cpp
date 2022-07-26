/*------Implementation of Linked List with all its basic function--------*/
class Node{
    public:
    int val;
    Node * next;
    Node(){  //default constructor
        this->next = nullptr;
    }
    Node(int val,Node *next){  //parameterised constructor
        this->val = val;
        this->next = next;
    }
};
#include<bits/stdc++.h>
using namespace std;
class LinkedList{
    public:
    Node *head,*tail;
    int len;
    LinkedList(){
        head=tail=nullptr;
        len=0;
    }
    void takeinput(){
        cout<<"Enter list ( -1 to stop ): "<<endl;
        int data;
        cin>>data;
        while(data!=-1){
            Node* newNode = new Node(data,nullptr);
            if(head==nullptr){
                head=tail=newNode;
                len=1;
            }else{
                tail->next=newNode;
                tail=tail->next;
                len++;
            }cin>>data;
        }
    }
    void insertatbegin(int data){
        if(data==-1)return;
        Node* newNode = new Node(data,nullptr);
        if(head==nullptr){
            head=tail=newNode;
            len=1;}
        else {
            newNode->next=head;
            head=newNode;len++;
        }
    }
    void insert(int data,int idx){
        if(data==-1)return;
        if(idx<0 or idx>len){
            return;
        }
        else if(idx==0){
            insertatbegin(data);
        }else if(idx==len){
            insertatend(data);
        }else{
            Node* newNode = new Node(data,nullptr);
            Node* tmp=head,*prev=head;
            while(tmp!=nullptr and idx!=0){
                prev=tmp;
                tmp=tmp->next;idx--;
            }
            prev->next=newNode;
            newNode->next=tmp;
            len++;
        }
    }
    int  index(int data){
        Node* tmp=head;
        int idx=0;
        while(tmp->next!=nullptr ){
            if(tmp->val==data)return idx;
            idx++;tmp=tmp->next;
        }
        return -1;
    }
    void insertatend(int data){
        if(data==-1)return;
        Node* newNode = new Node(data,nullptr);
        if(head==nullptr){
            head=tail=newNode;len=1;}
        else {
            tail->next=newNode;
            tail=tail->next;len++;
        }
    }
    void insertafter(int data,int val){
        if(data==-1)return;
        int idx=index(data)+1;
        if(idx==-1)return;
        else if(idx==len){insertatend(data);}else{
        Node* newNode = new Node(data,nullptr);
        Node* tmp=head,*prev=head;
        while(tmp!=nullptr and idx!=0){
                prev=tmp;
                tmp=tmp->next;idx--;
        }
        prev->next=newNode;
        newNode->next=tmp;
        len++;}
    }
    void insertinsortedlist(int data){
        if(data==-1)return;
        if(head->val>data){insertatbegin(data);return;}
        Node* tmp=head,*prev=head;
        while(tmp!=nullptr and tmp->val<data){
            prev=tmp;
            tmp=tmp->next;
        } 
        if(tmp==nullptr){
            insertatend(data);
        }else{
            Node* newNode = new Node(data,nullptr);
            prev->next=newNode;
            newNode->next=tmp;len++;
        }
    }
    private:
    Node* insertrecurive(Node* root,int data,int idx){
        if(root==nullptr)return;
        if(idx==0){
           Node* newNode = new Node(data,nullptr);
           newNode->next=root;
           return newNode;
        }
        Node* newhead=insertrecurive(root->next,data,idx-1);
        head->next=newhead;
        return head;
    }public:
    void insertrecurive(int data,int pos){
        Node* tmp=head;
        insertrecurive(tmp,data,pos);
    }
    int  deletebegin(){
        Node* tmp=head;
        int val=head->val;
        head=head->next;
        len--;
        delete(tmp);
        return val;
    }
    int  deleteend(){
        Node* tmp=head,*prev=head;
        while(tmp!=tail ){
            prev=tmp;
            tmp=tmp->next;
        }
        Node* p=tail;
        int ans=tail->val;
        prev->next=nullptr;
        tail=prev;
        delete(p);
        len--;
        return ans;
    }
    int deleteith(int pos){
        if(pos<0 or pos>=len)return -1;
        else if(pos==0)return deletebegin();
        int idx=pos;
        Node* tmp=head,*prev=head;
        while(tmp->next!=nullptr and (idx--)>0){
            prev=tmp;tmp=tmp->next;
        }
        Node* Next=tmp->next;
        int val=tmp->val;
        delete(tmp);len--;
        prev->next=Next;
        return val;
    }
    void print(){
        cout<<"Current List : ";
        Node* tmp=head;
        while(tmp->next!=nullptr){
            cout<<tmp->val<<" -> ";
            tmp=tmp->next;
        }cout<<tmp->val<<endl;
    }
    private:
    void printrecursive(Node* root){
        if(root==nullptr){
            return;
        }
        if(root->next==nullptr){
            cout<<root->val<<endl;
            return;
        }
        cout<<root->val<<" -> ";
        printrecursive(root->next);
    }public:
    void printhelp(){
        Node* tmp=head;
        printrecursive(tmp);
    }
    int length(){
        cout<<"Length of Linked list is : ";
        return len;
    }
   
};
int main(){
    LinkedList *l1=new LinkedList();
    l1->takeinput();
   // l1->insertinsortedlist(23);
    l1->deletebegin();
    l1->deleteend();
    l1->deleteith(2);
    l1->print();
    cout<<l1->length()<<endl;
    delete l1;
}
