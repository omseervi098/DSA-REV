#include<iostream>
using namespace std;
void printSubstrings(char input[]) {
    int k=0;
    //take o(n^3) time 
    for(;input[k]!=0;k++)
    {
        for(int i=k;input[i]!=0;i++)
        {
            for(int j=k;j<=i;j++)
            {
                  cout<<input[j];
            }
            cout<<endl;
        }
    }
}
void subString(string s, int n)
{
    //time o(n^3) 
    for (int i = 0; i < n; i++)
        for (int len = 1; len <= n - i; len++)
            cout << s.substr(i, len) << endl;
}
void printSubstrings(string str)
{
 
    // take o(n^2) time o(n) space
    for (int i = 0; i < str.length(); i++) {
        string subStr;
        for (int j = i; j < str.length(); j++) {
            subStr += str[j];
            cout << subStr << endl;
        }
    }
}