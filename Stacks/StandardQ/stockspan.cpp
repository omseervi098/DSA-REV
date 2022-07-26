/*
Afzal has been working with an organization called 'Money Traders' for the past few years. The organization is into the money trading business. His manager assigned him a task. For a given array/list of stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which the price of the stock was less than today's price.
For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].

Explanation:

On the sixth day when the price of the stock was 75, the span came out to be 4, because the last 4 prices(including the current price of 75) were less than the current or the sixth day's price.

Similarly, we can deduce the remaining results.

Afzal has to return an array/list of spans corresponding to each day's stock's price. Help him to achieve the task.
Sample Input 1:
4
10 10 10 10

Sample Output 1:
1 1 1 1 
*/
#include <bits/stdc++.h>
#include <stack>
using namespace std;

int* stockSpan(int *price, int size)  {
	//bruteforce o(n^2) space o(1)
    int cnt=1;
    int* arr=new int[size];
    for(int i=size-1;i>=0;i--)
    {
        cnt=1;
        for(int j=i-1;j>=0;j--)
        {
             if(price[i]<=price[j])
                break;
             else
                 cnt++;
        }
        arr[i]=cnt;
        
    }
    return arr;
}
int* stockSpan(int *price, int size)  {
	// time o(n) and space o(n)
    stack<int>s; int n=size;
    int *span=new int[n];
    s.push(0);
    span[0]=1;
    for(int i=1;i<n;i++){
        while(!s.empty() and price[s.top()]<price[i])
        s.pop();
        if(s.empty()){
            span[i]=i+1;
        }else{
            span[i]=i-s.top();
        }
        s.push(i);

    }return span;
}
int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}