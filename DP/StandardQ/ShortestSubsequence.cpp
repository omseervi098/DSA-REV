/*
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
*/
#include<bits/stdc++.h>
using namespace std;
//Recurive --O(2^min(m,n))
int solve(string s,string t,int sta=0,int stb=0){
    if(stb==t.size())
       return 1;
    if(sta==s.size())
       return 1001;
    int op1=solve(s,t,sta+1,stb);
    int i=stb;
    for(i=stb;i<t.size();i++){
        if(t[i]==s[sta])
             break;
    }
    if(i==t.size()) return 1;
    int op2=1+solve(s,t,sta+1,i+1);
    return min(op1,op2);
}
//Memoization -- O(M*N)
int solve(string s,string t,int sta=0,int stb=0,int** dp){
    if(stb==t.size())
       return 1;
    if(sta==s.size())
       return 1001;
    int m=s.size(),n=t.size();
    if(dp[m][n]!=-1) dp[m][n];
    int op1=solve(s,t,sta+1,stb,dp);
    int i=stb;
    for(i=stb;i<t.size();i++){
        if(t[i]==s[sta])
             break;
    }
    if(i==t.size()) return 1;
    int op2=1+solve(s,t,sta+1,i+1,dp);
    dp[m][n]=min(op1,op2);
    return dp[m][n];
}
//DP --O(M*N)
#include<bits/stdc++.h>
int solve(string S, string T) {
    int m = S.size();
	int n = T.size();
	int dp[m+1][n+1];
 
    // T string is empty
    for (int i = 0; i <= m; i++)
        dp[i][0] = 1;
 
    // S string is empty
    for (int i = 0; i <= n; i++)
        dp[0][i] = 1005;
 
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch = S[i-1];
            int k;
            for (k = j-1; k >= 0; k--)
                if (T[k] == ch)
                    break;
 
            // char not present in T
            if (k == -1)
                dp[i][j] = 1;
            else
               dp[i][j] = min(dp[i-1][j], dp[i-1][k] + 1);
        }
    }
 
    int ans = dp[m][n];
    if (ans >= 1005)
        ans = -1;
 
    return ans;
}