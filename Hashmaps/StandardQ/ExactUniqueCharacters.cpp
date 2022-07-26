/*
Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.
Sample Input 1 :

ababacd

Sample Output 1 :

abcd

*/
//Time O(N)
#include <iostream>
#include <string>
#include<unordered_map>
using namespace std;
string uniqueChar(string s){
    unordered_map<char,int> map;
    for(auto it:s)
    map[it]+=1;
    string ns="";
    for(auto it:s){
        if(map.count(it)){
            ns+=it;
            map.erase(it);
        }
    }
    return ns;
}
int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}