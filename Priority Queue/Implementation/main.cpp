#include <iostream>
#include <vector>
#include "heap.h"
using namespace std;
int main(){
    heap h1;
    for(int i=0;i<5;i++){
        int t;
        cin>>t;
        h1.push(t);
    }
    cout<<h1.get()<<endl;
    cout<<h1.getsize()<<endl;
    while(h1.getsize()!=0){
        cout<<h1.pop()<<endl;
    }
}