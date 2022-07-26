/*
Interleave The First Half Of The Queue With The Second Half 
Problem Statement
You have been given a queue of integers. You need to rearrange the elements of the queue by interleaving the elements of the first half of the queue with the second half.
Note :
The given queue will always be of even length.

For example :
If N= 10
and Q = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
then the output will be
Q = [10, 60, 20, 70, 30, 80, 40, 90, 50, 100]

*/
#include<bits/stdc++.h>
// time o(n) and space o(2n)
#include<bits/stdc++.h>
void interLeaveQueue(queue < int > & q) {
    queue<int> firsthalf;
    queue<int> secondhalf;
    int k=q.size()/2;
    while(q.size()){
        if(q.size()>k){
            firsthalf.push(q.front());q.pop();
        }else {
            secondhalf.push(q.front());q.pop();
        }
    }
    queue<int> ans;
    while(firsthalf.size() and secondhalf.size()){
        q.push(firsthalf.front());firsthalf.pop();
        q.push(secondhalf.front());secondhalf.pop();
    }
   
}
//better optimised by using stack for interleaving 
/*
    Time complexity: O(N)
    Space complexity: O(N)

    Where N is the size of the queue.
*/
void interLeaveQueue(queue < int > & q) {

    // Initialize an empty stack of int type.
    stack < int > s;
    int halfSize = q.size() / 2;

    // Push first half elements into the stack.
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    // Enqueue back the stack elements.
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Dequeue the first half elements of queue and enqueue them back.
    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    // Again push the first half elements into the stack.
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    // Interleave the elements of queue and stack.
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}