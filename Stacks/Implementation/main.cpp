#include<iostream>
#include "stackusingLL.h"
using namespace std;
int main(){
    stack<char> a;
    a.push('a');
    a.push('b');
    a.push('c');
    a.push('d');
    a.push('e');
    cout<<a.peek()<<endl;
    cout<<a.pop()<<endl;
    a.push('d');
    cout<<a.getsize()<<endl;
}