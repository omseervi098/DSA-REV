
/*
For a given two-dimensional integer array/list of size (N x M), print the array/list in a sine wave order, i.e, print the first column top to bottom, next column bottom to top and so on.

Sample Input 1:

1
3 4 
1  2  3  4 
5  6  7  8 
9 10 11 12

Sample Output 1:

1 5 9 10 6 2 3 7 11 12 8 4

Sample Input 2:

2
5 3 
1 2 3 
4 5 6 
7 8 9 
10 11 12 
13 14 15
3 3
10 20 30 
40 50 60
70 80 90

Sample Output 2:

1 4 7 10 13 14 11 8 5 2 3 6 9 12 15 
10 40 70 80 50 20 30 60 90 


*/
#include<bits/stdc++.h>
using namespace std;
void wavePrint(int **input, int n, int m)
{
    int r=0,c=0;
    while(c<m){
        if(c%2==0){
            for(r=0;r<n;r++){
                cout<<input[r][c]<<" ";
            }c++;
        }else {
            for(r=n-1;r>=0;r--){
                cout<<input[r][c]<<" ";
            }c++;
        }
    }
}