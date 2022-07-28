/*
Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Note : Order of words does not matter.
Sample Input 1 :
7
do dont no not note notes den
no

Sample Output 2 :
no
not
note
notes

Sample Input 2 :
7
do dont no not note notes den
de

Sample Output 2 :
den

Sample Input 3 :
7
do dont no not note notes den
nom

Sample Output 3 :
(Empty) There is no word which starts with "nom"
*/
#include<bits/stdc++.h>
using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    void print(TrieNode* node,string w){
        if(node==nullptr)return;
        if(node->isTerminal)cout<<w<<endl;
        for(int i=0;i<26;i++){
            if(node->children[i]){
               string t=w+node->children[i]->data;
               print(node->children[i],t);
            }
        }
    }
    void autocomplete(TrieNode* node,string pattern,string output){
        if(node==nullptr) return;
        if(pattern.size()==0) {
            if(node->isTerminal)
            cout<<output<<endl;
            for(int i=0;i<26;i++){
                if(node->children[i]){
                    string t=output+node->children[i]->data;
                    print(node->children[i],t);
                }
            }
        }
        autocomplete(node->children[pattern[0]-'a'],pattern.substr(1),output+pattern[0]);
    }
    void autoComplete(vector<string> input, string pattern) {
        for(auto it:input)
          insertWord(it);
        string output="";
        autocomplete(root,pattern,output);
    }
};