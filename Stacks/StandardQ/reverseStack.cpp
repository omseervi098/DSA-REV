/*
Sample Input 1:
6
1 2 3 4 5 10

Note:
Here, 10 is at the top of the stack.

Sample Output 1:
1 2 3 4 5 10
Note:
Here, 1 is at the top of the stack.

*/
#include <iostream>
#include <stack>
using namespace std;
//one approch can be 3 stacks 
//another is we can use recursion time o(n^2) and space o(n)
void reverseStack(stack<int> &input, stack<int> &extra) {
    if(input.size()==0)return ;
    int temp=input.top();input.pop();
    reverseStack(input, extra);
    while(!input.size()){
        extra.push(input.top());input.pop();
    }input.push(temp);
    while(extra.empty()){
        input.push(extra.top());extra.pop();
    }
}
int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}
