/*
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible
Sample Input 1 :
3
1 2 3
4

Sample Output 1 :
4

Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).

Sample Input 2 :
6
1 2 3 4 5 6
250

Sample Output 2 :
13868903
*/
//Recurive Solution O(2^n)
int countWaysToMakeChange(int s[], int n, int value){
    if(value==0)return 1;
    if(value<0||n<=0) return 0;
    return countWaysToMakeChange(s,n,value-s[n-1])+countWaysToMakeChange(s,n-1,value);
}
//Memoization Solution O(n*value)
int helper(int s[],int n,int value,int **out)
{
    if(value==0)
        return 1;
    if(value<0)
        return 0;
    if(n<=0)
        return 0;
    if(out[n][value]!=-1)
        return out[n][value];
    int ans=helper(s,n,value-s[n-1],out)+helper(s,n-1,value,out);
    out[n][value]=ans;
    return ans;
}
//DP Solution O(n*value)
int countWaysToMakeChange(int s[], int n, int value){
    int ** out=new int*[n+1];
    for(int i=0;i<=n;i++)
        out[i]=new int[value+1];
    for(int i=0;i<=n;i++)
        out[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=value;j++)
        {
            int x=0;
            if(j-s[n-i]>=0)
                x=out[i][j-s[n-i]];
            out[i][j]=x+out[i-1][j];
        }
    }
    return out[n][value];
}