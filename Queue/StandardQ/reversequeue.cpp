/*

REVERSE QUEUE
Sample Input 1:
1
6
1 2 3 4 5 10

Note:
Here, 1 is at the front and 10 is at the rear of the queue.

Sample Output 1:
10 5 4 3 2 1
*/
#include <iostream>
#include <queue>
using namespace std;
void reverseQueue(queue<int> &input) {
	// time o(n) space o(n)
    if(input.size()==0)return;
    int temp=input.front();input.pop();
    reverseQueue(input);
    input.push(temp);
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}