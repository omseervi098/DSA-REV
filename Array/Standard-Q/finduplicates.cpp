#include<iostream>
#include<algorithm>
using namespace std;
int findduplicate(int * arr,int n){
    //O(n^2)
    for(int i=0;i<n;i++){
        int j=0;
        for( j=0;j<n;j++){
            if(i!=j and arr[i]==arr[j])
               return arr[i];
        }
    }
    return -1;
}
int findduplicate1(int *arr,int n){
    //O(nlogn)
    sort(arr,arr+n);
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
           return arr[i];
        }
    }return -1;
}
int findduplicate2(int *arr,int n){
    //o(n) work if have 1 dup
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int natsum=((n-1)*(n-2))/2;
    return sum-natsum;
}
// we can also use hashmaps o store frequency of each integer and then find duplicate one whose count  will be more than one
// that will also take O(n)
int main(){
    int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findduplicate2(arr,n);
}