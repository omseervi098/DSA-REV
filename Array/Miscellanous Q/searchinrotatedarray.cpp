//problem link: https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_630450?leftPanelTab=1
/*
Aahad and Harshit always have fun by solving problems. Harshit took a sorted array consisting of distinct integers and rotated it clockwise by an unknown amount. For example, he took a sorted array = [1, 2, 3, 4, 5] and if he rotates it by 2, then the array becomes: [4, 5, 1, 2, 3].
After rotating a sorted array, Aahad needs to answer Q queries asked by Harshit, each of them is described by one integer Q[i]. which Harshit wanted him to search in the array. For each query, if he found it, he had to shout the index of the number, otherwise, he had to shout -1.
For each query, you have to complete the given method where 'key' denotes Q[i]. If the key exists in the array, return the index of the 'key', otherwise, return -1.
Sample Input 1:

4
2 5 -3 0
2
5
1

Sample Output 1:

1
-1

*/
//one simple way is to do linear search
//another is binary search
int search(int* arr, int n, int key) {
    //time complexity: o(logn)
    int st=0,en=n-1;
    while(st<=en){
         int mid=(st+en)/2;
         if(arr[mid]==key)
             return mid;
         else if(arr[st]<=arr[mid]){
             if(arr[st]<=key and key<=arr[mid])
                 en=mid-1;
             else
                 st=mid+1;
         }else {
             if(arr[en]>=key and key>=arr[mid])
                 st=mid+1; 
             else
                 en=mid-1;
         }
    } 
    return -1;
}
//one more approach to this question is
// first getting d i.e by how much index it was rotated
//get d in logn time 
// then apply binary seach on left and right subpart
//this will also take logn time
int  pivot(int* arr, int n)
{
   int lo = 0, hi = n - 1, mid;
   while (lo < hi)
   {
       mid = (hi +lo) / 2;
       if (arr[mid] >= arr[0])
       {
           lo = mid + 1;
       }
       else
       {
           hi = mid;
       }
   }
  return lo;
}
int binary_search(int arr[],int lo,int hi,int key)
{
   int mid=lo+(hi-lo)/2;
   while(lo<=hi)
   {  
       if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            lo=mid+1;
        else
            hi=mid-1;
        mid=lo+(hi-lo)/2;
   }
return -1;
}
int search(int* arr, int n, int key) {
   int s=0,e=n-1,ans=0;
   int pivot_res=pivot(arr,n);
   if(arr[pivot_res]<=key && key<=arr[e])
   {
       ans= binary_search(arr,pivot_res,e,key);
   }
   else
   {
       ans=binary_search(arr,s,pivot_res-1,key);
   }
   return ans;
}