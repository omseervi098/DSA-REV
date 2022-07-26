/*
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order)
Sample Input 1:
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0

Sample Output 1:
0 1 2 5 6 9 45 78 90 100 234
*/
#include<bits/stdc++.h>
using namespace std;
//Time --O(N*K *LOG(N*K))
//SPACE --O(N*K)
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    priority_queue<int,vector<int>,greater<int>> min;
    for(int i=0;i<input.size();i++)
    {
        vector<int> *current=input[i];
        for(int j=0;j<current->size();j++)
            min.push(current->at(j));
    }
    vector<int> v;
    while(!min.empty())
    {
        v.push_back(min.top());
        min.pop();
    }
    return v;
}