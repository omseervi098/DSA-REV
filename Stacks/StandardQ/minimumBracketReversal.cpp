/*
For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
If the expression can't be balanced, return -1.
Example:

Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.

Sample Input 1:
{{{

Sample Output 1:
-1

Sample Input 2:
{{{{}}

Sample Output 2:
1
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
//time o(n) and space o(n)
int countBracketReversals(string input){
     if(input.size()%2==1)return -1;
    stack<char> s;
    for(auto it:input){
        if(it=='{')
        s.push(it);
        else if(it=='}'){
            if(s.empty())
            s.push(it);
            else if(s.top()=='{')
            s.pop();
            else if(s.top()=='}')
            s.push(it);
        }
    }
    int cnt=0;
    while(s.size()){
        char a=s.top();s.pop();
        char b=s.top();s.pop();
        if(a==b)cnt+=1;
        if(a=='{' and b=='}') cnt+=2;
    }return cnt;
}
int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}