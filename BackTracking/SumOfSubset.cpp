/*
You are given an array of integers and a target K. You have to find the count of subsets of the given array that sum up to K.
Note:
1. Subset can have duplicate values.
2. Empty subset is a valid subset and has sum equal to zero.
Sample Input 1:
1
5 6
2 4 4 3 1

Sample Output 1:
3
*/
//time-- O(2^N)
#include <bits/stdc++.h>
using namespace std;
int subsetSum(int arr[], int n, int i, int sum)
{
    if (i == n)
    {
        if (sum == 0)
            return 1;
        else
            return 0;
    }
    int count = 0;
    if (sum - arr[i] >= 0)
        // include
        count += subsetSum(arr, n, i + 1, sum - arr[i]);
    // not include
    count += subsetSum(arr, n, i + 1, sum);
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << subsetSum(arr, n, 0, k) << endl;
    }
    return 0;
}
