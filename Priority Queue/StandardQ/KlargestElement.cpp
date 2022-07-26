/*
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Sample Input :

13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4

Sample Output :

12
16
20
25
*/
//TIME O(NLOGK) AND space O(K)
#include<bits/stdc++.h>
vector<int> kLargest(int arr[], int n, int k){
    priority_queue<int,vector<int>,greater<int>> min;
    for(int i=0;i<k;i++)
    {
        min.push(arr[i]);
    }
    vector<int> v;
    for(int i=k;i<n;i++)
    {
        if(arr[i]>min.top())
        {
            min.pop();
            min.push(arr[i]);
        }
    }
    while(!min.empty())
    {
        v.push_back(min.top());
        min.pop();
    }
    return v;

}
