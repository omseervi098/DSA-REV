#include<bits/stdc++.h>
using namespace std;
//Time O(2^n)  Recursive Solution
int lcs(string s,string t){
    if(s.size()==0 || t.size()==0)
        return 0;
    if(s[0]==t[0]){
        return 1+lcs(s.substr(1),t.substr(1));
    }else{
        return max(lcs(s.substr(1),t),lcs(s,t.substr(1)));
    }
}
//Memoization O(M*N)
int lcs(string s,string t,int m,int n,int** dp){
    if(s.size()==m||t.size()==n)
        return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    if(s[m]==t[n]){
        dp[m][n]=1+lcs(s,t,m+1,n+1,dp);
        return dp[m][n];
    }else{
        dp[m][n]=max(lcs(s,t,m+1,n,dp),lcs(s,t,m,n+1,dp));
        return dp[m][n];
    }
}
//Dp O(M*N) 
int lcs(string s,string t){
    if(s.size()==0||t.size()==0)return 0;
    int m=s.size(),n=t.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i]==s[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}