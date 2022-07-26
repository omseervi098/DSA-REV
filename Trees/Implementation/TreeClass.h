#include<bits/stdc++.h>
using namespace std;
template <typename V> class Tnode{
    public:
    V val;
    vector <Tnode*> children;
    Tnode(V val){
        this->val=val;
    }
};
template <typename T> class tree{
   
    Tnode<T>* root;
    int h;
    public:
    tree(){
        root=NULL;
    }
    private:
    Tnode<T>* takeinputrecur(){
        T val;
        int n;
        cout<<"Enter data :";
        cin>>val;
        Tnode<T>* newnode = new Tnode(val);
        cout<<"Enter no of children of "<<val<<" node:";
        cin>>n;
        for(int i=0;i<n;i++){
            Tnode<T> * child=takeinputrecur();
            newnode->children.push_back(child);
        }
        return newnode;
    }
    Tnode<T>* takeinputbetter(){
        T val;
        int n;
        cout<<"Enter data :";
        cin>>val;
        Tnode<T>* newnode = new Tnode(val);
        queue<Tnode<T>*> q;
        q.push(newnode);
        while(q.size()){
            Tnode<T>* child = q.front();
            q.pop();
            cout<<"Enter no of children of "<<child->val<<" node:";
            cin>>n;
            for(int i=0;i<n;i++){
                int childval;
                cin>>childval;
                Tnode<T>* newchild = new Tnode<T>(childval);
                child->children.push_back(newchild);
                q.push(newchild);
            }
        }return newnode;
    }
    public:
    void takeinput(){
        root=takeinputbetter();
    }
    private:
    void print(Tnode<T> * root){
        cout<<root->val<<":";
        for(int i=0;i<root->children.size();i++){
            cout<<root->children[i]->val<<",";
        }cout<<endl;
        for(int i=0;i<root->children.size();i++)
            print(root->children[i]);
        
    }
    void printpostorder(Tnode<T> * root){
        stack<Tnode<T>*> s;
        stack<int> ans;
        s.push(root);
        while(s.size()){
            Tnode<T>* node=s.top();
            s.pop();
            ans.push(node->val);
            for(auto it:node->children){
                s.push(it);
            }
        }
        while(!ans.empty())
        {
            cout<<ans.top()<<" ";
            ans.pop();
        }cout<<endl;
    }
    void printlevelwise(Tnode<T> * root){
        queue<Tnode<T>*> q;
        q.push(root);
        while(q.size()){
            Tnode<T>* child = q.front();
            cout<<child->val<<":";
            q.pop();
            for(int i=0;i<child->children.size();i++){
                cout<<child->children[i]->val<<",";
                q.push(child->children[i]);
            }cout<<endl;
        }
    }
    public:
    void print(){
        printdfsiterative(root);
        printlevelwise(root);
    }
};