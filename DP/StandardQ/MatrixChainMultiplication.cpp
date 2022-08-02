/*
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Sample Input 1:
3
10 15 20 25

Sample Output 1:
8000

SamplE Output Explanation:
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000. 
*/
//Recursive Solution --exponential
#include<bits/stdc++.h>
int helper(int *arr,int st,int end){
    if(end-st==1||st==end) return 0;
    int ans=INT_MAX;
    for(int i=st+1;i<end;i++){
        ans=min(ans,(helper(arr,st,i)+helper(arr,i,end)+arr[i]*arr[st]*arr[end]));
    }
    return ans;
}
int matrixChainMultiplication(int* arr, int n) {
    return helper(arr,0,n);
}
//Memoization --O(N^3)
int helper(int *arr,int st,int end,vector<vector<int>> &dp){
    if(end-st==1||st==end) return 0;
    int ans=INT_MAX;
    if(dp[st][end]!=-1) return dp[st][end];
    for(int i=st+1;i<end;i++){
        ans=min(ans,(helper(arr,st,i,dp)+helper(arr,i,end,dp)+arr[i]*arr[st]*arr[end]));
    }
    dp[st][end]=ans;
    return ans;
}
int matrixChainMultiplication(int* arr, int n) {
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return helper(arr,0,n,dp);
}

//DP --O(n^3)

int matrixChainMultiplication(int* arr, int n) {
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++)
        dp[i][i]=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            int end=j+i-1;
            dp[j][end]=INT_MAX;
            for(int k=j;k<end;k++)
              dp[j][end]=min(dp[j][end],(dp[j][k]+dp[k+1][end]+arr[j-1]*arr[k]*arr[end]));
        }
    }
    return dp[1][n];
}