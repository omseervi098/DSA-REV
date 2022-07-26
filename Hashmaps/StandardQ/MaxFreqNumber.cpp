#include<bits/stdc++.h>
#include<unordered_map>
int highestFrequency(int arr[], int n) {
    // Time O(N) and space O(1)
    unordered_map<int,int> m;
    int max=-1,data;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(m.at(arr[i])>max)
        {
            max=m[arr[i]];
            data=arr[i];
        }
    }
    return data;
}