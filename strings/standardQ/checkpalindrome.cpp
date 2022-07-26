#include <iostream>
#include <cstring>
using namespace std;
// one approach is we can reverse string and store it in other string array
// but this take  o(n) both for time and space
void reverse(char str[]){
    int st=0,end=strlen(str)-1;
    while(st<end){
        char temp=str[st];
        str[st++]=str[end];
        str[end--]=temp;
    }
}
bool checkPalindrome(char str[]) {
    char rev[1000];
    strcpy(rev, str);
    reverse(rev);
    cout<<rev<<" "<<str<<endl;
    if(strcmp(rev,str)==0) return true;
    return false;   
}
//o(n) time but constant space
bool checkPalindrome1(char str[]) {
    int st=0,end=strlen(str)-1;
    while(st<end){
        if(str[st]!=str[end]){
            return false;
        }
        st++;end--;
    }
    return true;
}
int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome1(str) ? "true" : "false");
}