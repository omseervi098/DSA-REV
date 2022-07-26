/*
Sample Input 1:

1
4 4 
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16

Sample Output 1:

1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 

*/
#include<bits/stdc++.h>
using namespace std;
//o(r*c)
void spiralPrint(int **input, int nRows, int nCols)
{
    int row_st=0,col_st=0,col_en=nCols-1,row_en=nRows-1;
    while(col_st<=col_en || row_st<=row_en)
    {
        for(int i=col_st;i<=col_en;i++)
        cout<<input[row_st][i]<<" ";
        row_st++;
        for(int i=row_st;i<=row_en;i++)
        cout<<input[i][col_en]<<" ";
        col_en--;
        for(int i=col_en;i>=col_st;i--)
        cout<<input[row_en][i]<<" ";
        row_en--;
        for(int i=row_en;i>=row_st;i--)
        cout<<input[i][col_st]<<" ";
        col_st++;
    }
}
}