/*
You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.
Sample Input 1 :
6
6 2 1 3 7 5

Sample Output 1 :
6 4 2 2 3 4
*/
#include<bits/stdc++.h>
using namespace std;
void findMedian(int *arr, int n)
{
    // Write your code here
    if(n==0)
        return;
    priority_queue<int,vector<int>,greater<int>> min;
    priority_queue<int> max;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            max.push(arr[i]);
            cout<<max.top()<<" ";
            continue;
        }
        if(arr[i]<max.top())
            max.push(arr[i]);
        else
            min.push(arr[i]);
        int temp=0;
        if(max.size()>min.size())
            temp=max.size()-min.size();
        else
            temp=-(min.size()-max.size());
        if(temp>1||temp<-1)
        {
            if(temp>1)
            {   min.push(max.top());
                max.pop();
                temp-=2;
            }else
            {
                max.push(min.top());
                min.pop();
                temp+=2;
            }
        }
            if(temp==0)
            {
                cout<<(max.top()+min.top())/2<<" ";
            }else if(temp==1)
            {
                cout<<max.top()<<" ";
            }else if(temp==-1)
            {
                cout<<min.top()<<" ";
            }
    }
}