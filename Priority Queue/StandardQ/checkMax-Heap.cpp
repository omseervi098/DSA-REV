/*
Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.
Sample Input 1:
8
42 20 18 6 14 11 9 4

Sample Output 1:
true
*/
//Takes O(N) and space O(1)
bool isMaxHeap(int arr[], int n) {
    int pi=0;
    int l=1,r=2;
    while(l<n){
        l=2*pi+1;r=2*pi+2;
        if(arr[pi]<arr[l])
            return false;
        if(r<n and arr[pi]<arr[r])
            return false;
        pi++;
    }return true;
}
//Another approach
bool isMaxHeap(int arr[], int n) {
    for(int i=1;i<n;i++)
          if(arr[i]>arr[(i-1)/2])
              return false;
    return true;
}