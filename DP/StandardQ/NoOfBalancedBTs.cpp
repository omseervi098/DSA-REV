/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h)
Sample Input 1:
3

Sample Output 1:
15
*/
//Recursive O(2^h)
int noofbalancedBST(int h){
    if(h<=1) return 1;
    int x=noofbalancedBST(h-1);
    int y=noofbalancedBST(h-2);
    return x*x+2*x*y;
}
//Memoization O(h)
int noofbalancedBST(int h,int *dp){
    if(h<=1) return 1;
    if(dp[h]!=-1) return dp[h]
    int x=noofbalancedBST(h-1);
    int y=noofbalancedBST(h-2);
    dp[h]=x*x+2*x*y;
    return dp[h];
}
//DP O(h)
int noofbalancedBST(int h){
    vector<int> v(h+1,1);
    for(int i=2;i<=h;i++){
        dp[i]=dp[i-1]*dp[i-1]+2*dp[i-1]*dp[i-2];
    }
    return dp[h];
}
