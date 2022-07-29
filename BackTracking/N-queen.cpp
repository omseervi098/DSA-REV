/*
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Note: Don't print anything if there isn't any valid configuration.
Sample Input 1:
4

Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 

*/
//Time O(N*(2^N))
#include<bits/stdc++.h>
using namespace std;
int arr[11][11];
bool isafe(int n,int row,int col)
{
    for(int i=0;i<row;i++)
    {
        if(arr[i][col])
            return false;
    }
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
    {
        if(arr[i][j])
            return false;
    }
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
    {
        if(arr[i][j])
            return false;
    }
    return true;
    
}
void nqueen(int n,int row)
{
    if(row==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(isafe(n,row,i))
        {
            arr[row][i]=1;
            nqueen(n,row+1);
            arr[row][i]=0;
        }
    }
    return;
}
void placenqueen(int n){
    memset(arr,0,11*11*sizeof(int));
    nqueen(n,0);
}
int main(){
    
    // write your code here
    int n;
    cin>>n;
    placenqueen(n);
    return 0;
}