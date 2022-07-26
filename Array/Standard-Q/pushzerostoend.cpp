#include<iostream>
#include<algorithm>
using namespace std;
//o(n)
void pushZeroesEnd(int * input,int n){
    int nzero=0;
    for(int i=0;i<n;i++){
        if(input[i]!=0){
            swap(input[i],input[nzero]);
            nzero++;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        pushZeroesEnd(input, n);

		for (int i = 0; i < n; i++)
		{
			cout << input[i] << " ";
		}
    }
}