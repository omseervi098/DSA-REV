#include<unordered_map>
int pairSumtozero(int *arr, int n) {
	// Time O(N) and space o(1)
    unordered_map<int,int> m;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(m.count(-arr[i]))
            ans+=m[-arr[i]];
        m[arr[i]]+=1;
    }
    return ans;
}