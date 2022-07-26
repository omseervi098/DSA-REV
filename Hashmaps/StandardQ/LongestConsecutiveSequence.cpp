/*
You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 

Sample Output 1 :
8 12 

Sample Input 2 :
7
3 7 2 1 9 8 41

Sample Output 2 :
7 9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.
*/
#include<bits/stdc++.h>
using namespace std;
//BruteForce is using sorting
//TIME O(nlog(n))
//SPACE O(1)
#include<bits/stdc++.h>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_map<int,int> map;
    for(int i=0;i<n;i++)
        map[arr[i]]=i;
    sort(arr,arr+n);
    int mxlen=0,mxst=0,idx=INT_MAX;
    for(int i=0;i<n;i++){
        int st=arr[i];
        int k=i;
        while(i<n-1 and arr[i]+1==arr[i+1])
            i++;
        if((i-k)+1>mxlen){
            mxlen=(i-k)+1;
            mxst=st;
            idx=map[st];
        }   
        if(i-k+1==mxlen){
            if(idx>map[st])
            {
                idx=map[st];
                mxst=st;
                mxlen=(i-k)+1;
            }
        }
        
    }
    vector<int> v;
    v.push_back(mxst);
    v.push_back(mxst+mxlen-1);
    return v;
}

//Better Optimised using two map 
//Time O(N)
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_map<int,int> map; 
    unordered_map<int,bool> m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]=true;
        map[arr[i]]=i;
    }
    int mxst=0,mxlen=0,size=0;
    for(int i=0;i<n;i++){
        size=0;
        if(m[arr[i]]){
            int st=arr[i];
            size++;
            int j=st+1;
            while(m.count(j)){
                m[j]=false;
                size++;
                j++;
            }
            j=st-1;
            while(m.count(j)){
                st=j;
                m[j]=false;
                size++;
                j--;
            }
            if(size>mxlen){
                mxst=st;
                mxlen=size;
            }
            if(size==mxlen){
                if(map[st]<map[mxst]){
                    mxst=st;
                    mxlen=size;
                }
            }
        }
    }
    vector<int>v;
    v.push_back(mxst);
    v.push_back(mxst+mxlen-1);
    return v;
}


