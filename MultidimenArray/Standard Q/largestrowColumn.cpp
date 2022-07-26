/*
or a given two-dimensional integer array/list of size (N x M), you need to find out which row or column has the largest sum(sum of all the elements in a row/column) amongst all the rows and columns.

Sample Input 1 :

1
2 2 
1 1 
1 1

Sample Output 1 :

row 0 2

Sample Input 2 :

2
3 3
3 6 9 
1 4 7 
2 8 9
4 2
1 2
90 100
3 40
-10 200

Sample Output 2 :

column 2 25
column 1 342

*/
#include <bits/stdc++.h>
using namespace std;
//time o(r*c)
void findLargest(int **input, int r, int c)
{
    int mxcolsum=INT_MAX,maxcolidx=0;
    for(int i=0;i<r;i++){
        int sum=0;
        for(int j=0;j<c;j++){
            sum+=input[i][j];
        }
        if(mxcolsum<sum){
            mxcolsum=sum;
            maxcolidx=i;
        }
    }
    int mxrowsum=INT_MAX,maxrowidx=0;
    for(int i=0;i<c;i++){
        int sum=0;
        for(int j=0;j<r;j++){
            sum+=input[j][i];
        }
        if(mxrowsum<sum){
            mxrowsum=sum;
            maxrowidx=i;
        }
    }
    if(mxrowsum>mxcolsum){
        cout<<"row "<<maxrowidx<<" "<<mxrowsum<<endl;
    }else{
         cout<<"column "<<maxcolidx<<" "<<mxcolsum<<endl;
    }
}