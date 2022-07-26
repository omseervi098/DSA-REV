/*
For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.
Example:

Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.

Sample Input 1:
a+(b)+c 

Sample Output 1:
true

Explanation:
The expression can be reduced to a+b+c. Hence, the brackets are redundant.

Sample Input 2:
(a+b)

Sample Output 2:
false

*/
#include <iostream>
#include <string>
#include<stack>
using namespace std;
//both approach have same time and space complexity o(n) and o(n)
//one approach can be that is we maintain no of charater between "(" and ")" and check if(cnt==1 or 0) then it is reduntant
bool checkRedundantBrackets(string expression) {
	// Write your code here
    int i = 0;
    stack<char> s1;
    int count = 0;
    
    while(expression[i] != '\0'){

        if(expression[i] == ')'){
            if(s1.top() == '('){
                if(count < 2){
                    return true;
                }
				count = 0;
                s1.pop();
                i++;
            }
            else{
            	s1.pop();
            	count++;
            }
            
        }
        else{
            s1.push(expression[i]);
            i++;
        }
    }
    return false;
        
}
bool checkRedundantBrackets(string exp) {
    //another approach is we can push the "(" and ")" and operator to stack which have operater in between "(" and ")"is not redundant
     stack<char> s;
     for(int i=0;exp[i]!='\0';i++)
     {
         if(exp[i]=='+'||exp[i]=='*'||exp[i]=='-'||exp[i]=='*'||exp[i]=='(')
         {
             s.push(exp[i]);
         }
         else if(exp[i]==')'){
             bool check =false;
             while(s.top()!='('&& !s.empty())
             {
                 s.pop();
                 check=true;
             }
             if(!check)
             {
                 return true;
             }
          
         }
     }
    return false;
}
int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}