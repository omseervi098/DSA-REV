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
template <typename V> class queue{
    Node<V>* head;
    Node<V>* tail;
    int size;
    public:
    queue(){
        head=tail=NULL;
        size=0;
    }
    void push(int data){
        Node<V>* newnode=new Node<V>(data,nullptr);
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
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
    V front(){
        if(head==NULL){
            return -1;
        }
        return head->val;
    }
};