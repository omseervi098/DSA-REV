/*
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
Sample Input 1 :

4 2 3

Sample Output 1 :

Whis

Sample Input 2 :

10 2 4

Sample Output 2 :

Beerus

Explanation to Sample Input 1:

Initially, there are 4 coins,  In the first move, Beerus can remove either 1, 2, or 3 coins in all three cases, Whis can win by removing all the remaining coins. 
*/
//Recursive O(3^n)
bool helper(int n,int x,int y,bool flag){
    if(n==1||n==x||n==y) return flag;
    if(n<0) return !flag;
    bool one= helper(n-1,x,y,!flag);
    bool two=helper(n-x,x,y,!flag);
    bool three=helper(n-y,x,y,!flag);
    if(!one and !two and !three) return false;
    return true;
}
string findWinner(int n, int x, int y)
{
    bool beerus=true;
    bool ans=helper(n,x,y,beerus);
    if(ans)
    return "Beerus";
    return "Whis";
}
//Memoized O(N)
#include<bits/stdc++.h>
using namespace std;
bool helper(int n,int x,int y,bool flag,vector<int> &dp){
    if(n==1||n==x||n==y) {
        dp[n]=true;
        return true;}
    if(dp[n]!=-1) return dp[n];
    if(n<x){
        bool one=!helper(n-1,x,y,!flag,dp);
        dp[n]=one;
        return one;
    }
    if(n<y){
        bool two=!(helper(n-x,x,y,!flag,dp) and helper(n-1,x,y,!flag,dp));
        dp[n]=two;
        return two;
    }else{
        bool c=helper(n-y,x,y,!flag,dp);
        bool b=helper(n-x,x,y,!flag,dp);
        bool a=helper(n-1,x,y,!flag,dp);
        dp[n]=!(a and b and c);
        return dp[n];
    }
}
string findWinner(int n, int x, int y)
{
    if(x>y) swap(x,y);
    vector<int> dp(n+1,-1);
    bool beerus=true;
    bool ans=helper(n,x,y,beerus,dp);
    if(ans)
        return "Beerus";
    return "Whis";
}

//Dp O(N)
string findWinner(int n, int x, int y)
{
	// Write your code here .
   int dp[n + 1]; 
  
    // Initial values 
    dp[0] = false; 
    dp[1] = true; 
  
    for (int i = 2; i <= n; i++) { 
  
        // If A losses any of i-1 or i-x 
        // or i-y game then he will 
        // definitely win game i 
        if (i - 1 >= 0 and !dp[i - 1]) 
            dp[i] = true; 
        else if (i - x >= 0 and !dp[i - x]) 
            dp[i] = true; 
        else if (i - y >= 0 and !dp[i - y]) 
            dp[i] = true; 
  
        // Else A loses game. 
        else
            dp[i] = false; 
    } 
  
    // If dp[n] is true then A will 
    // game otherwise  he losses 
    string s="Whis";
    if (dp[n])
    {
        s="Beerus";
        return s;
    }
    else return s;
}