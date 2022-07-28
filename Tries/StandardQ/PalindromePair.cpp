/*
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.
Sample Input 1 :

4
abc def ghi cba

Sample Output 1 :

true

Explanation of Sample Input 1:

"abc" and "cba" forms a palindrome

Sample Input 2 :

2
abc def

Sample Output 2 :

false

Explanation of Sample Input 2:

Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'
*/
//Time --o(N*M) 
//Space --o(M*N)
//N--> no of strings
//M--> avergage word length
#include<bits/stdc++.h>
using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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

    bool add(TrieNode *root, string word) {
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
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }
    /*..................... Palindrome Pair................... */
    bool checkWordForPalindrom(string word){
        int st=0,end=word.size()-1;
        while(st<end){
            if(word[st]!=word[end]) return false;
            st++;end--;
        }
        return true;
    }
    bool checkRemainingBranches(TrieNode* node,string word){
        if(node->isTerminal)
        {
            if(checkWordForPalindrom(word)) return true;
        }
        for(int i=0;i<26;i++){
            TrieNode* child=node->children[i];
            if(!child)continue;
            string fwd=word+child->data;
            if(checkRemainingBranches(child,fwd))
                return true;
        }
        return false;
    }
    bool doesPairExist(TrieNode* node,string words,int i){
        if(words.size()==0) return true;
        if(i==words.size()){
            if(node->isTerminal)
                return true;
            return checkRemainingBranches(node,"");
        }
        int idx=words[i]-'a';
        TrieNode* child=node->children[idx];
        if(child==NULL){
            if(node->isTerminal)
                return checkWordForPalindrom(words.substr(i));
            return false;
        }
        return doesPairExist(child,words,i+1);
    }
    bool isPalindromePair(vector<string> words) {
        for(auto it:words){
            string s1=it;
            reverse(s1.begin(),s1.end());
            add(s1);
        }
        for(auto it:words){
            if(doesPairExist(root,it,0)) return true;
        } return false;
    }

};