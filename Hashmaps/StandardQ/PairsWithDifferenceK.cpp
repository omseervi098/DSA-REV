/*
You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.
Sample Input 1 :

4 
5 1 2 4
3

Sample Output 1 :

2

*/
#include<bits/stdc++.h>
using namespace std;
int getPairsWithDifferenceK(int *arr, int n, int k) {
	//Time  --->	O(N)
	//Space  --->   O(1)
	unordered_map<int,int> m;
	int cnt=0;
	for(int i=0;i<n;i++){
		int temp=arr[i]+k;
		int temp1=arr[i]-k;
		if(m.count(temp))
			cnt+=m[temp];
		else if(m.count(temp1))
		    cnt+=m[temp];
		m[arr[i]]+=1;
	}
	return cnt;
}