/*
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance

Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/
//Recursive Time O(3^min(N,M))
#include<bits/stdc++.h>
using namespace std;
int editDistance(string s,string t){
    if(s.size()==0||t.size()==0)
        return s.size()==0?t.size():s.size();
    if(s[0]==t[0]) 
        return editDistance(s.substr(1),t.substr(1));
    else
        return min(1+editDistance(s,s[0]+t),min(1+editDistance(s,t.substr(1)),1+editDistance(s.substr(1),t.substr(1))));
}
//Memoization O(M*N) and space O(m*n)
int helper(string s, string t, int **output) {
	int m = s.size();
	int n = t.size();
	if(s.size() == 0 || t.size() == 0) {
		if(s.size()!=0)
        {
            output[m][n]=s.size();
            return s.size();
        }
        else{
            output[m][n]=t.size();
            return t.size();
        }
	}
    if(output[m][n] != -1) {
		return output[m][n];
	}
    int ans;
	if(s[0] == t[0]) {
		ans= helper(s.substr(1), t.substr(1),output);
	}
	else {

		int a = helper(s.substr(1),t,output)+1;
		int b = helper(s,t.substr(1),output)+1;
		int c = helper(s.substr(1), t.substr(1),output)+1;
		ans= min(a, min(b, c));
	}

	// Save your calculation
	output[m][n] = ans;

	// Return ans
	return ans;
}
//DP TIME O(M*N) and space O(m*n)
int editDistance(string s,string t){
    int m=s.size(),n=t.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<=n;i++)
       dp[0][i]=i;
    for(int i=0;i<=m;i++)
       dp[i][0]=i;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    return dp[m][n];
}