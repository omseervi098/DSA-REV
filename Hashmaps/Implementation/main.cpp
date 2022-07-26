#include <iostream>
#include "unordered_map.h"
using namespace std;
int main(){
    unmap<int> umap;
    umap.insert("ab",1);
    umap.insert("bc",2);
    umap.insert("cd",3);
    umap.insert("de",4);
    umap.insert("ef",5);
    umap.insert("ab",6);
    cout<<umap.remove("ab")<<endl;
    cout<<umap.remove("bc")<<endl;
    cout<<umap.getval("cd")<<endl;
    cout<<umap.getval("de")<<endl; 
}