/*
For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.

Sample Input 1 :
(()()())

Sample Output 1 :
true

Sample Input 2 :
()()(()

Sample Output 2 :
false

*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
//time o(n) 
bool isBalanced(string expression) 
{
    stack<char> s;
    for(auto it:expression){
        if(it=='('){
            s.push(it);
        }else {
            if(s.empty()){
                s.push(it);
            }
            else if (s.top()=='(')
            s.pop();
            else
            break;
        }
    }
    return s.empty(); 
}
int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}