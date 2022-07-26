/*
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false
*/
// o (n)
#include<bits/stdc++.h>
bool helper(char* input,int st,int end){
    if(st>=end)return true;
    if(input[st]!=input[end])return false;
    return helper(input,st+1,end-1);
}

bool checkPalindrome(char input[]) {
    return helper(input,0,strlen(input)-1);
}
