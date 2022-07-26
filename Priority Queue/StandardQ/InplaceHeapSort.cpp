/*
Time O(nlogn) and space o(1)
*/
#include <bits/stdc++.h>
using namespace std;
void heapSort(int arr[], int n) {
    //heap build
    for(int i=1;i<n;i++){
       int ci=i;
       while(ci>0)
       {
          int pi=(ci-1)/2;
          if(arr[ci]<arr[pi])
          {
              swap(arr[ci],arr[pi]);
          }else
              break;
          ci=pi;
       }
    }
    //removemin
    while(n>0){
        swap(arr[0],arr[n-1]);
        n=n-1;
        int pi=0;
        int lefti=2*pi+1,righti=2*pi+2;
        while(lefti<n){
            int minidx=pi;
            if(arr[minidx]>arr[lefti])
                minidx=lefti;
            if(righti<n && arr[minidx]>arr[righti])
                minidx=righti;
            if(minidx==pi)
                break;
            swap(arr[minidx],arr[pi]);
            pi=minidx;
            lefti=2*pi+1;
            righti=2*pi+2;
        }
    }
}