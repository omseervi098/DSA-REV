/*
Geometric Sum
Given k, find the geometric sum i.e.

1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 

using recursion.
Input format :

Integer k

Output format :

Geometric sum (upto 5 decimal places)

Constraints :

0 <= k <= 1000

Sample Input 1 :

3

Sample Output 1 :

1.87500

*/
#include<math.h>
double geometricSum(int k) {
    if(k==0) return 1;
    return 1/pow(2,k)+geometricSum(k-1);

}



