#include<iostream>
#include<vector>
using namespace std;
//time o(n) space o(n)
int firstIndex(int *input,int n,int x){
    if(n==0) return -1;
    if(input[0]==x) return 0;
    int idx = firstIndex(input+1,n-1,x);
    return idx==-1?-1:idx+1;
}
//time o(n) space o(n)
int lastIndex(int *input,int n,int x,int st){
    if(n==st) return -1;
    int idx=lastIndex(input,n,x,st+1);
    if(idx!=-1){
        return idx;
    }
    if(input[st]==x){
            return st;
    }
    else
        return -1;
}
//time o(n) space o(n)
void allIndex(int *input,int n,int x,vector<int> &output){
    if(n==0){
        return;
    }
    if(input[0]==x)
    output.push_back(0);
    allIndex(input+1,n-1,x,output);
    for(auto &it:output)
        it+=1;
}
int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << firstIndex(input, n, x) << endl;

}


