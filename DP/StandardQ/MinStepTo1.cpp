/*
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:

1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  

*/
//Recursive Approach
//TIME -- O(3^N)
//Space -- O(N)
int countMinStepsToOne(int n)
{
	if(n<=1) return 0;
    int cnt=1+countMinStepsToOne(n-1);
    int cnt2=9999,cnt3=9999;
    if(n%2==0)
    cnt2=1+countMinStepsToOne(n/2);
    if(n%3==0)
    cnt3=1+countMinStepsToOne(n/3);
    return min(cnt,min(cnt3,cnt2));
}
//Memoization
//Time O(N) and Space O(N)
int countMinStepsToOne(int n,vector<int> &v){
    if(n<=1) return 0;
    if(v[n]!=-1) return v[n];
    int cnt=1+countMinStepsToOne(n-1);
    int cnt2=9999,cnt3=9999;
    if(n%2==0)
    cnt2=1+countMinStepsToOne(n/2);
    if(n%3==0)
    cnt3=1+countMinStepsToOne(n/3);
    v[n]=min(cnt,min(cnt3,cnt2));
    return v[n];
}
//DP
//Time O(N) and space O(N)
int countMinStepsToOne(int n){
    vector<int> ans(n+1);
    ans[0]=0;
    ans[1]=0;
    for(int i=2;i<=n;i++){
        int cnt2=9999,cnt3=9999;
        if(i%2==0)cnt2=1+ans[i/2];
        if(i%3==0) cnt3=1+ans[i/3];
        ans[i]=min(1+ans[i-1],min(cnt2,cnt3));
    }
    return ans[n];
}