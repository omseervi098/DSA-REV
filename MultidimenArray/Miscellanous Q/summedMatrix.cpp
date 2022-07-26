// link: https://www.codingninjas.com/codestudio/problems/summed-matrix_981304
/*
Sample Input 1:

2
4 2
3 4

Sample Output 1:

1
3

*/
//one bruteforce approach is to that run two nested loop i and j check whose i+j==q  and increment counter
// this take O(n^2) time
//another better approach
long long int query(long long int n, long long int q) {
    // Write your code here
    //this take constant time
    if(q<n+1){
        return q-1;
    }else{
        return 2*n-q+1;
    }
}