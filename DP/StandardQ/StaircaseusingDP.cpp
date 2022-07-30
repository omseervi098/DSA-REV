/*
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Sample Input 1:
4
Sample Output 1:
7

Sample Input 2:
10
Sample Output 2:
274
*/
//Recursive solution
//Time O(3^n) and space o(n)
long staircase(int n)
{
    if(n==0)return 1;
	if(n==2||n==1) return n;
    return staircase(n-1)+staircase(n-2)+staircase(n-3);
}
//Dp O(N) and space O(N)
long staircase(int n)
{
    if(n==2||n==1)return n;
    vector<long> ans(n+1);
    ans[0]=1;
    ans[1]=1;
    ans[2]=2;
    for(int i=3;i<=n;i++){
        ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
    }
    return ans[n];
}

