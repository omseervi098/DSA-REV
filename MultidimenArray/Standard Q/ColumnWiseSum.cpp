#include<iostream>
using namespace std;
// O(r*c)

int main(){
    int c,r;
    cin>>r>>c;
    int **a=new int*[r];
    int colsum=0;
    for(int i=0;i<r;i++){
        *a=new int[c];
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<c;i++){
        colsum=0;
        for(int j=0;j<r;j++){
            colsum+=a[j][i];
        }
        cout<<colsum<<endl;
    }
}


