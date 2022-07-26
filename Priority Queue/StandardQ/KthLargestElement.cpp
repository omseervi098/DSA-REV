/*
Given an array A of random integers and an integer k, find and return the kth largest element in the array.
Note: Try to do this question in less than O(N * logN) time.
Sample Input 1 :
6
9 4 8 7 11 3
2

Sample Output 1 :
9

Sample Input 2 :
8
2 6 10 11 13 4 1 20
4

Sample Output 2 :
10
*/

//Time O(nlogk) and space O(k)
#include<queue>
int kthLargest(int* arr, int n, int k) {
    // Write your code here
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
    return v[0];
}