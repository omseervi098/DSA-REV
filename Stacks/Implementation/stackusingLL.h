template <typename T>
class Node{
    public:
    T val;
    Node * next;
    Node(){  //default constructor
        this->next = nullptr;
    }
    Node(T val,Node *next){  //parameterised constructor
        this->val = val;
        this->next = next;
    }
};
//push o(1) pop o(1) and allother operation in o(1)
template <typename V> class stack{
    Node<V>* head;
    int size;
    public:
    stack(){
        head=NULL;
        size=0;
    }
    void push(int data){
        Node<V>* newnode=new Node<V>(data,nullptr);
        if(head==NULL){
            head=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
        size++;
    }
    V pop(){
        if(head==NULL){return -1;}
        int val=head->val;
        head=head->next;
        size--;
        return val;
    }
    int getsize(){
        return size;
    }
    bool empty(){
        return size==0;
    }
    V peek(){
        if(head==NULL){
            return -1;
        }
        return head->val;
    }
};