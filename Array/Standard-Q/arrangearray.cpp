#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[1000];
    int st=0,end=n-1;
    for(int i=1;i<=n and st<=end;i++){
        if(i%2==0)
          arr[end--]=i;
        else
          arr[st++]=i;
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i-1]<<" ";
    }
}