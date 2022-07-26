/*
You are given an array arr of length N. You have to return a list of integers containing the NGE(next greater element) of each element of the given array. The NGE for an element X is the first greater element on the right side of X in the array. Elements for which no greater element exists, consider the NGE as -1.
For Example :

If the given array is [1, 3, 2], then you need to return [3, -1, -1]. Because for 1, 3 is the next greater element, for 3 it does not have any greater number to its right, and similarly for 2.

*/
//bruteforce o(n^2) time and o(1) space
vector<int> nextGreater(vector<int> &arr, int n) {
     vector<int> ans(n);
     for(int i=0;i<n;i++)
     {
          int k=-1;
         for(int j=i+1;j<n;j++){
             if(arr[j]>arr[i]){
                 k=arr[j];break;
             }
         }
         ans[i]=k;
     }return ans;
}
//optmised using stack 
//time o(n) and space o(n)
#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
     vector<int> ans(n,-1);
     stack<int> s;
    
     for(int i=n-1;i>=0;i--)
     {
          if(s.empty()){
              s.push(arr[i]);
              continue;
          }
          if(!s.empty() and arr[i]<s.top()){
              ans[i]=s.top();
              s.push(arr[i]);
          }else if(!s.empty() and arr[i]>=s.top()){
              while(!s.empty() and arr[i]>=s.top())s.pop();
              if(!s.empty())
                  ans[i]=s.top();
              s.push(arr[i]);
          }
     }
    return ans;
}