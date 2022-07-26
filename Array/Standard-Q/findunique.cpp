#include<iostream>
#include<algorithm>
using namespace std;
int findunique(int * arr,int n){
    //O(n^2)
    for(int i=0;i<n;i++){
        int j=0;
        for( j=0;j<n;j++){
            if(i!=j and arr[i]==arr[j])
               break;
        }
        if(j==n)
            return arr[i];
    }
    return -1;
}
int findunique1(int *arr,int n){
    //O(nlogn)
    sort(arr,arr+n);
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]!=arr[i+1]){
            cnt=1;
        }else
        {
            while(arr[i]==arr[i+1]){
                i++;cnt++;
            }
        }
        if(cnt==1)return arr[i];
    }return -1;
}
int findunique2(int *arr,int n){
    //o(n)
    int xors=0;
    for(int i=0;i<n;i++)
        xors^=arr[i];
    return xors;
}
// we can also use hashmaps o store frequency of each integer and then find unique one whose count  will be one
// that will also take O(n)
int main(){
    int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findunique2(arr,n);
}