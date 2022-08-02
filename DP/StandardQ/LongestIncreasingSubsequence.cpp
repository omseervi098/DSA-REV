/*
Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order
Sample Input 1 :
6
5 4 11 1 16 8

Sample Output 1 :
3

Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).

Sample Input 2 :
3
1 2 2

Sample Output 2 :
3   
*/
#include<bits/stdc++.h>
using namespace std;
//Recursive Solution --O(2^n)
#include<bits/stdc++.h>
using namespace std;
int helper(int * arr,int n,int curr){
    if(curr==0) return 1;
    int cnt=1;
    for(int i=curr-1;i>=0;i--){
        if(arr[i]<arr[curr])
        {
            int ans=1+helper(arr,n,i);
            //cout<<arr[i]<<" "<<ans+1<<endl;
            cnt=max(cnt,ans);
        }
    }
    return cnt;
}
int longestIncreasingSubsequence(int* arr, int n) {
    int mx=0;
    for(int i=0;i<n;i++)
        mx=max(mx,helper(arr,n,i));
    return mx;
} 
//Memoization Solution  --O(n^2)
int helper(int * arr,int n,int curr,vector<int> &dp){
    if(curr==0) return 1;
    int cnt=1;
    if(dp[curr]!=-1)
    return dp[curr];
    for(int i=curr-1;i>=0;i--){
        if(arr[i]<arr[curr])
        {
            int ans=1+helper(arr,n,i);
            cnt=max(cnt,ans);
        }
    }
    dp[curr]=cnt;
    return cnt;
}
int longestIncreasingSubsequence(int* arr, int n) {
    int mx=0;
    vector<int> dp(n,-1);
    for(int i=0;i<n;i++)
        mx=max(mx,helper(arr,n,i,dp));
    return mx;
}
//DP Solution --O(n^2)
int longestIncreasingSubsequence(int* arr, int n) {
    vector<int> dp(n,1);
    int ans=1;
    for(int i=1;i<n;i++){
        int mx=1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                mx=max(mx,1+dp[j]);
            }
        }
        dp[i]=mx;
        ans=max(ans,mx);
    }return ans;
}

