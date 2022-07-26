#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int pairsum(int * arr,int n, int sum){
    //O(n^2)
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==sum){
                cout<<arr[i]<<" "<<arr[j]<<endl;cnt++;
            }
        }
    }return cnt;
}
int pairsum1(int * arr,int n,int sum){
    //using 2 pointer and sorting 
    //time complexity o(nlogn)+O(n)
    int cnt=0,st=0,end=n-1;
    sort(arr,arr+n);
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
//another way is to use hashmap
int pairsum2(int * arr,int n,int sum){
    int cnt=0;
    unordered_map<int,int> map;
    // time complexity O(n)
    for(int i=0;i<n;i++){
        int k=sum-arr[i];
        if(map.count(k)>0){
            int temp=0;
            while(temp<map[k]){
                cout<<arr[i]<<" "<<k<<endl;
                temp++;
            }
            cnt+=map[k];
            map[arr[i]]+=1;
        }else{
            map[arr[i]]+=1;
        }
    }
    return cnt;
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

		cout << pairsum2(input, size, x)<<endl;

		delete[] input;
	}
	
	return 0;
}