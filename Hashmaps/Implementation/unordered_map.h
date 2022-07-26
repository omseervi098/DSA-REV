#include<bits/stdc++.h>
using namespace std;
template <typename V> class node{
    public:
    string k;
    V val;
    node<V>* next;
    node(string k,V val){
        this->k=k;
        this->val=val;
        this->next=NULL;
    }
    ~node(){
        delete next;
    }
};
template <typename V> class unmap{
    node<V>** arr;
    int size;
    int capacity;
    public:
    unmap(){
        size=0;
        capacity=5;
        arr=new node<V>*[capacity];
        for(int i=0;i<capacity;i++)
            arr[i]=NULL;
    }
    private:
    int hashfn(string k){
        int ans=0;
        int pv=1;
        for(int i=k.length()-1;i>=0;i--)
            ans+=k[i]*pv;
            pv*=31;
        return ans%capacity;
    }
    void rehash(){
        node<V>** temp=arr;
        arr=new node<V>*[2*capacity];
        for(int i=0;i<2*capacity;i++)
            arr[i]=NULL;
        capacity*=2;
        size=0;
        for(int i=0;i<capacity/2;i++){
            node<V>* curr=temp[i];
            while(curr!=NULL){
                insert(curr->k,curr->val);
                curr=curr->next;
            }   
        }
        for(int i=0;i<capacity/2;i++)
            delete temp[i];
        delete[] temp;
    }
    public:
    void insert(string key,V val){
        int idx=hashfn(key);
        node<V>* temp=arr[idx];
        while(temp!=NULL)
        {
            if(temp->k==key)
            {
                temp->val=val;
                return;
            }
            temp=temp->next;
        }
        node<V>* newnode=new node<V>(key,val);
        newnode->next=arr[idx];
        arr[idx]=newnode;
        size++;
        double loadfactor=size/(double)(capacity);
        if(loadfactor>0.7)
           rehash();
    }
    V remove(string key){
        int idx=hashfn(key);
        node<V>* temp=arr[idx];
        node<V>* prev=NULL;
        while(temp!=NULL)
        {
            if(temp->k==key)
            {
                if(prev==NULL){
                    arr[idx]=temp->next;
                }
                else{
                    prev->next=temp->next;
                }
                temp->next=NULL;
                size--;
                return temp->val;
            }
            prev=temp;
            temp=temp->next;
        }
        return -1;
    }
    V getval(string key){
        int idx=hashfn(key);
        node<V>* temp=arr[idx];
        while(temp!=NULL)
        {
            if(temp->k==key)
            {
                return temp->val;
            }
            temp=temp->next;
        }
        return -1;
    }
    int getsize(){
        return size;
    }
    ~unmap(){
        for(int i=0;i<capacity;i++)
            delete arr[i];
        delete[] arr;
    }
};