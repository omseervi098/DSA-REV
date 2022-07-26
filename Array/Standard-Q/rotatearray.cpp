#include <iostream>
using namespace std;
void rotate(int *input, int d, int n)
{
    //bruteforce o(n^2)
    while(d>0)
    {
    int temp=input[0];
    for(int i=0;i<n-1;i++)
    {
        input[i]=input[i+1];
    }
    input[n-1]=temp;
    d--;
    }
}
void rotate1(int *input, int d, int n){
    // we can have temp arr of size d
    //time o(n) but space o(d)
    int temp[d];
    for(int i=0;i<d;i++)
    {
        temp[i]=input[i];
    }
    int k=0;
    for(int i=d;i<n;i++)
    {
        input[i-d]=input[i];
        k++;
    }
    for(int i=k;i<n;i++)
    {
        input[i]=temp[i-k];
    }

}
void reverse(int *input,int st,int en)
{
    while(st<=en){
        int temp=input[st];
        input[st]=input[en];
        input[en]=temp;
        st++;en--;
    }
}
void rotate2(int *input, int d, int n){
    //thrird is using reverse
    //time: o(n) but space o(1)
    reverse(input,0,n-1);
    reverse(input,0,n-d-1);
    reverse(input,n-d,n-1);
}
int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}