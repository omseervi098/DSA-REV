#include<bits/stdc++.h>
int maxArea(vector<int>& height) {
    //bruteforce o(n^2)
    int gmax=INT_MIN;
    int n=height.size();
    for(int i=0;i<n-1;i++){
        int mx=height[i];
        for(int j=i+1;j<n;j++){
            int temp=(j-i)*(min(height[i],height[j]));
            if(temp>mx)
                mx=temp;
        }
        gmax=max(mx,gmax);
    }
    return gmax;
}
//another approach using two pointer in O(n) TIME
#include<bits/stdc++.h>
int maxArea(vector<int>& height) {
    int gmax;
    int n=height.size();
    int st=0,end=n-1;
    gmax=0;
    while(st<end){
        gmax=max((abs(end-st))*min(height[st],height[end]),gmax);
        if(height[st]>height[end])
            end--;
        else if(height[end]>=height[st])
            st++;
    }
    return gmax;
}