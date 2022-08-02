/*
Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-

10 = 1^2 + 3^2 

Hence, answer is 1.
Note : x^y represents x raise to the power y
*/
int getAllWays(int a,int b){
    if(a<=1) return 1;
    int x=1,ans=0;
    while(pow(x,b)<=a){
        int subans=getAllWays(a-pow(x,b),b);
        ans++;
        x++;
    }
    return ans;
}
//b=2
//1 2 3 4 5 6 7 8 9 10
//
