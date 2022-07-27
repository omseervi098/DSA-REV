/*
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
Sample Input 1:
10 
95 -97 -387 -435 -5 -70 897 127 23 284

Sample Output 1:
5

Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 
*/
#include<bits/stdc++.h>
using namespace std;
//time O(n) and space O(1)
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int,int> prefsum;
    int sum=0,size=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(!sum)
            size=i+1;
        if(!prefsum.count(sum))
            prefsum[sum]=i;
        else
            size=i-prefsum[sum];
    }
    return size;
}
