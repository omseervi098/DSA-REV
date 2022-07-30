/*
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:

1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"

The cost of a path is defined as the sum of each cell's values through which the route passes.
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13

Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76

Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3 :
18
*/
//Recursive
//Time O(3^(M*N))
//space O(max(M,N))
#include<bits/stdc++.h>
using namespace std;
int minCostPath(int **input,int m,int n,int x,int y){
    
    if(x<0 ||y<0||x==m||y==n)return INT_MAX;
    if(x==m-1 and y==n-1) return input[x][y];  
    int down=minCostPath(input,m,n,x+1,y);
    int right=minCostPath(input,m,n,x,y+1);
    int diagonal=minCostPath(input,m,n,x+1,y+1);
    return input[x][y]+min(down,min(right,diagonal));
}
int minCostPath(int **input, int m, int n)
{
	return minCostPath(input,m,n,0,0);
}
//Memoization
//Time O(M*N) and space O(M*N)
int minCostPath(int **input,int m,int n,int x,int y,int **output){
    
    if(x<0 ||y<0||x==m||y==n)return INT_MAX;
    if(output[x][y]!=-1)return output[x][y];
    if(x==m-1 and y==n-1) return input[x][y];  
    int down=minCostPath(input,m,n,x+1,y);
    int right=minCostPath(input,m,n,x,y+1);
    int diagonal=minCostPath(input,m,n,x+1,y+1);
    output[x][y]=input[x][y]+min(down,min(right,diagonal));
    return output[x][y];
}
int minCostPath(int **input, int m, int n)
{
	return minCostPath(input,m,n,0,0);
}
//DP
//Time O(M*N) and space O(M*N)
int minCostPath(int **input, int m, int n)
{
	vector<vector<int>> dp(m,vector<int>(n,0));
    dp[m-1][n-1]=input[m-1][n-1];;
    for(int i=n-2;i>=0;i--)
        dp[m-1][i]=dp[m-1][i+1]+input[m-1][i];
    for(int i=m-2;i>=0;i--)
        dp[i][n-1]=dp[i+1][n-1]+input[i][n-1];
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j]=min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
        }
    }
    return dp[0][0];
}