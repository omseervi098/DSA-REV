/*
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Sample Input 1 :

6
5 5 10 100 10 5

Sample Output 1 :

110

Sample Input 2 :

6
10 2 30 20 3 50

Sample Output 2 :

90

Explanation of Sample Output 2 :

Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
*/
//Recursive Solution: Time O(2^n)
#include<bits/stdc++.h>
using namespace std;
int maxMoneyLooted(int *arr, int n)
{
    if(n<=0) return 0;
    int x=0,y=0;
    x+=arr[0]+maxMoneyLooted(arr+2,n-2);
    y+=maxMoneyLooted(arr+1,n-1);
    return max(x,y);
}
//Memoization Solution : Time O(n)
int helper(int *arr,int n,vector<int> &temp){
    if(n<=0) return 0;
    int x=0,y=0;
    if(temp[n]!=-1) return temp[n];
    x+=arr[0]+helper(arr+2,n-2,temp);
    y+=helper(arr+1,n-1,temp);
    temp[n]=max(x,y);
    return temp[n];
}
int maxMoneyLooted(int *arr, int n)
{
    vector<int> ans(n+1,-1);
    return helper(arr,n,ans);
}

//DP `Solution: Time O(nW)`
int maxMoneyLooted(int *arr,int n){
    vector<int> ans(n+1);
    ans[0]=0;
    ans[1]=arr[0];
    for(int i=2;i<=n;i++){
        ans[i]=max(arr[i-1]+ans[i-2],ans[i-1]);
    }
    return ans[n];
}