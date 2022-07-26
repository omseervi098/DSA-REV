#include <bits/stdc++.h>

// link to the problem :https://www.codingninjas.com/codestudio/problems/smallest-subarray-with-k-distinct-elements_630523?leftPanelTab=1

vector<int> smallestSubarrayWithKDistinct(vector<int> &arr, int k)
{
    //Bruteforce O(N^2) time and o(n) space 
    int n=arr.size();
    int st=0,end=n;
    for(int i=0;i<n;i++){
        unordered_set<int> s;
        int j;
        for(j=i;j<n;j++){
            s.insert(arr[j]);
            if(s.size()==k){
                if((j-i)<(end-st)){
                    st=i;
                    end=j;
                }break;
            }
        }
        if(j==n)
            break;
    }
    if(end==n)
        return {-1};
    else
        return {st,end};
}
vector<int> smallestSubarrayWithKDistinct(vector<int> &arr, int k)
{
    // better approach using sliding window approach
    //takes o(n) time and and o(k) space
    int n=arr.size();
    int st=0,end=n;
    int i=0,j=0;
    unordered_map<int,int> map;
    while(j<n){
        map[arr[j]]+=1;
        while(map.size()==k){
            map[arr[i]]-=1;
            if(map[arr[i]]==0)map.erase(arr[i]);
            if((j-i)<(end-st)){
                st=i;end=j;
            }
            i++;
        }j++;
    }
    if(end==n)
        return {-1};
    return {st,end};
}