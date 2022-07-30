/*
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
*/
//Recursive Time O(n^n)
#include<bits/stdc++.h>
using namespace std;
int minCount(int n)
{
	if(n==0||n==1)return n;
    int x=1,ans=INT_MAX;
    while(x*x<=n){
        int subans=1+minCount(n-x*x);
        ans=min(ans,subans);
        x++;
    }return ans;
}
//Memoization time o(n*sqrt(n))
int minCount(int n,vector<int> &an){
    if(n==0||n==1)return n;
    if(an[n]!=-1)return an[n];
    int x=1,ans=INT_MAX;
    while(x*x<=n){
        int subans=1+minCount(n-x*x);
        ans=min(ans,subans);
        x++;
    }
    an[n]=ans;
    return ans; 
}
//DP  o(n*sqrt(n))
int minCount(int n)
{     
    vector<int> ans(n+1);
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        int an=INT_MAX;
        for(int j=1;j*j<=i;j++){
            an=min(an,1+ans[i-j*j]);
        }
        ans[i]=an;
    }	
    return ans[n];
}