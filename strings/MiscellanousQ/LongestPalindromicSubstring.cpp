/*
Leetcode Problem no 5
Given a string s, return the longest palindromic substring in s.
 
Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

Constraints:
    1 <= s.length <= 1000
    s consist of only digits and English letters
*/
//bruteforce O(2^n)
class Solution {
public:
    int l=0,r=0;
    int helper(string &s,int st,int end){
        if(st>end) return 0;
        if(st==end) return 1;
        cout<<st<<" "<<end<<endl;
        if(s[st]==s[end]){
            int size=end-st+1;
            int subans=helper(s,st+1,end-1);
            if(size==2+subans)
            {
                if(end-st>r-l){
                   l=st;
                   r=end;
                }
                return size;
            }
        }
        return max(helper(s,st+1,end),helper(s,st,end-1));
    }
    string longestPalindrome(string s) {
        int n=s.size();
       // vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        helper(s,0,n-1);
        return s.substr(l,r-l+1);
    }
};
//Memoization --O(N*N)
class Solution {
public:
    int l=0,r=0;
    int helper(string &s,int st,int end,vector<vector<int>> &dp){
        if(st>end) return 0;
        if(st==end) return 1;
        if(dp[st][end]!=-1)return dp[st][end];
        if(s[st]==s[end]){
            int size=end-st+1;
            int subans=helper(s,st+1,end-1,dp);
            if(size==2+subans)
            {
                if(end-st>r-l){
                   l=st;
                   r=end;
                }
                dp[st][end]=size;
                return size;
            }
        }
        dp[st][end]=max(helper(s,st+1,end,dp),helper(s,st,end-1,dp));
        return dp[st][end];
    }
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        helper(s,0,n-1,dp);
        return s.substr(l,r-l+1);
    }
};

//DP --O(N^2)
string longestPalindrome(string s) {
    int n=s.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    int l=0,r=0;
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j) dp[i][j]=1;
            else if(s[i]==s[j] and dp[i+1][j-1]==(j-i+1))
            {
                if(j-i>r-l)
                {
                    l=i;r=j;
                }
                dp[i][j]=2+dp[i+1][j-1];
            }else
            dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }
    return s.substr(l,r-l+1);
}
//  Manesher algo --O(N)

