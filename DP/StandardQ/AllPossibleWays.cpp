/*
Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-

10 = 1^2 + 3^2 

Hence, answer is 1.
Note : x^y represents x raise to the power y
*/
//Recursive 
int helper(int n,int b,int currno){
    if(n<0) return 0;
    if(n==0) return 1;
    int ans=0;
    for(int i=currno;pow(i,b)<=n;i++)
         ans+=helper(n-pow(i,b),b,i+1);
    return ans;
}
//Memoization --
#include<bits/stdc++.h>
int helper(int x,int n,int curNo,int *dp){
    if(x<0){
        return 0;
    }
    if(x==0){
        return 1;
    }

    int ans=0;

    for(int i=curNo;pow(i,n)<=x;i++){
            ans+=helper(x-pow(i,n),n,i+1,dp);
    }
    dp[x]=ans;
    return ans;    
}
int getAllWays(int n, int b) {
    int dp[100000];
    for(int i=0;i<100000;i++){
        dp[i]=-1;
    }
    return helper(n,b,1,dp);
}