#include<iostream>
#include "queueusingLL.h"
using namespace std;
int main(){
    queue<char> a;
    a.push('a');
    a.push('b');
    a.push('c');
    a.push('d');
    a.push('e');
    a.push('e');
    a.push('e');
    a.push('e');
    a.push('e');
    cout<<a.front()<<endl;
    a.push('d');
    cout<<a.pop()<<endl;
    cout<<a.pop()<<endl;
    a.push('e');
    cout<<a.pop()<<endl;
    cout<<a.pop()<<endl;
    a.push('e');
    a.push('e');
    a.push('e');
    a.push('e');
    a.push('e');
    cout<<a.pop()<<endl;
    cout<<a.getsize()<<endl;
}