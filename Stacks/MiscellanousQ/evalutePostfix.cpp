/*
Problem Statement
An expression is called the postfix expression if the operator appears in the expression after the operands.
Example :
Infix expression: A + B  *  C - D 
Postfix expression:  A B + C D - *
Given a postfix expression, the task is to evaluate the expression. The answer could be very large, output your answer modulo (10^9+7). Also, use modular division when required.
Sample input 1
2
2 3 1 * + 9 -
1 2 3 + * 8 -

Sample output 1
-4
-3
num is between 1 to 100
*/
//time o(n) and space o(n)
#include<bits/stdc++.h>
int evaluatePostfix(string &exp) {
    stack<int> s;
    int mod=1e9+7;
    int ans=0;
    for(int i=0;i<exp.size();i++){
        if(exp[i]==' ')
            continue;
        if(exp[i]>='0' and exp[i]<='9'){
            string temp="";
        while(exp[i]!=' ')
        {
            temp+=exp[i];
            i++;
        }
        int num=stoi(temp);
        s.push(num);}
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
            int a,b;
            if(!s.empty())
              a=s.top();s.pop();
            if(!s.empty())
              b=s.top();s.pop();
            if(exp[i]=='+')
                s.push((b+a)%mod);
            else if(exp[i]=='-')
                s.push((b-a)%mod);
            else if(exp[i]=='*')
                s.push((b*a)%mod);
            else if(exp[i]=='/')
                s.push((b/a)%mod);
            ans=s.top();
            
        }
    }
    return s.top();
}
