/*
A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?
Sample Input 1 :

4
1 2 4 5
5 4 8 6
5

Sample Output 1 :

13

Sample Input 2 :

5
12 7 11 8 9
24 13 23 15 16
26

Sample Output 2 :

51
*/
//Recursive Solution: Time O(2^n)
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    if(maxWeight<=0||n<=0) return 0;
    if(weights[0]>maxWeight)
        return knapsack(weights+1,values+1,n-1,maxWeight);
    int inc=values[0]+knapsack(weights+1,values+1,n-1,maxWeight-weights[0]);
    int notinc=knapsack(weights+1,values+1,n-1,maxWeight);
    return max(inc,notinc);
}
//DP Solution: Time O(nW)
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    int dp[n+1][maxWeight+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=maxWeight;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(weights[i-1]<=j)
                dp[i][j]=max(values[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][maxWeight];
}