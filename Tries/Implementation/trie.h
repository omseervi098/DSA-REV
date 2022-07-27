#include<bits/stdc++.h>
using namespace std;
class Trinode {
    public:
    Trinode ** child;
    char val;
    bool isterminal;
    Trinode(char val){
        child=new Trinode*[26];
        for(int i=0;i<26;i++)
            child[i]=nullptr;
        isterminal= false;
        this->val=val;
    }
};
class trie{
    Trinode* root;
    public:
    trie(){
        root=new Trinode('\0');
    }
    private:
    void insert(Trinode* node,string word){
        if(!word.size()) {
            node->isterminal=true;
            return;}
        int idx=word[0]-'a';
        Trinode* child;
        if(node->child[idx]!=NULL)
            child=node->child[idx];
        else
        {
            child=new Trinode(word[0]);
            node->child[idx]=child;
        }
        insert(child,word.substr(1));
    }
    bool search(Trinode* node,string word){
        if(!word.size()) return node->isterminal;
        int idx=word[0]-'a';
        if(node->child[idx])
            return search(node->child[idx],word.substr(1));
        else
            return false;
    }
    void remove(Trinode* node,string word){
        if(!word.size()) {
            node->isterminal=true;
            return;
        }
        Trinode* child;
        int idx=word[0]-'a';
        if(node->child[idx]!=NULL)
            child=node->child[idx];
        else
            return;
        remove(child,word.substr(1));
        if(!child->isterminal){
            for(int i=0;i<26;i++){
                if(root->child) return;
            }
            delete child;
            root->child[idx]=NULL;
        }
    }
    public:
    void insert(string word){
        insert(root,word);
    }
    bool search(string word){
        return search(root,word);
    }
    void remove(string word){
        remove(root,word);
    }
};
