/*
Leaders in array
Given an integer array A of size n. Find and print all the leaders present in the input array. An array element A[i] is called Leader, if all the elements following it (i.e. present at its right) are less than or equal to A[i].
Print all the leader elements separated by space and in the same order they are present in the input array.
Input Format :

Line 1 : Integer n, size of array
Line 2 : Array A elements (separated by space)

Output Format :
    leaders of array (separated by space)

Sample Input 1 :

6
3 12 34 2 0 -1

Sample Output 1 :

34 2 0 -1

*/
#include<iostream>
#include<climits>
using namespace std;
void Leaders(int* arr,int len)
{//bruteforce solution take o(n^2) time
        int i,j;
        for(i=0;i<len-1;i++){
            for(j=i+1;j<len;j++){
                if(arr[i]<arr[j]){
                    break;
                    }
            }
            if(j==len){
                cout<<arr[i]<<" ";
            }
          }
        cout<<arr[len-1];
}
void Leaders1(int* arr,int len){
    //better we can start from last and we can maintain largest
    //this will take o(n) time and o(n) space
    int j=0;
    vector<int> ans;
    for(int i=0;i<len;i++){
        if(arr[i]>=mx){
            mx=arr[i];
            ans.push_back(mx);
        }
    }
    //copy ans to arr
}
int main()
{
    int len;
    cin>>len;
	int *arr = new int[len + 1];
	
	for(int i=0;i<len;i++)
	{
		cin>>arr[i];
	}
	Leaders(arr,len);
}
