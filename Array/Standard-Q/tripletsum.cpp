#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int tripletsum(int* arr,int n,int x){
    //O(n^3)
    int cnt=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==x){
                cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                cnt++;}
            }
        }
    }
    return cnt;
}
//Another which can do this in O(n^2) is using pairsum 
// for every three a,b,c and their sum as d
// we can find pair whose sum is d-c
int pairsum1(int * arr,int st,int n,int sum){
    int cnt=0,end=n-1;
    while(st<end){
        if(arr[st]+arr[end]>sum){
            end--;
        }else if(arr[st]+arr[end]<sum){
            st++;
        }else{
            if(arr[st]==arr[end]){
                int temp=(end-st)+1;
                cnt+=(temp*(temp-1))/2;
                return cnt;
            }
            int tempst=st,tempend=end;
            while(tempst<=tempend and arr[st]==arr[tempst]){
                tempst++;
            }
            while(tempend>=tempst and arr[tempend]==arr[end])
                tempend--;
            int c1=(tempst-st),c2=(end-tempend);
            cnt+=c1*c2;
            st=tempst;end=tempend;
        }
    }
    return cnt;
}
int tripletsum1(int* arr,int n,int x){
    sort(arr,arr+n);
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=pairsum1(arr,i+1,n,x-arr[i]);
        cout<<cnt<<endl;
    }
    return cnt;
}
//Finally we can  also use hashmap 
//it is way easier than the two pointer approach
//O(n^2) time complexity
int tripletsum2(int * arr, int n,int x){
    int cnt=0;
    for(int i=0;i<n;i++){
        unordered_map<int,int> map;
        for(int j=i+1;j<n;j++){
            if(map.count(x-arr[i]-arr[j])>0){
                cnt+=map[x-arr[i]-arr[j]];
                int t=map[x-arr[i]-arr[j]];
                while(t>0){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<x-arr[i]-arr[j]<<endl;
                    t--;
                }
            }
            map[arr[j]]+=1;
        }
    }return cnt;
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletsum2(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}