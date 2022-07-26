#include <iostream>
using namespace std;

int binarySearch(int *input, int n, int val)
{
    int st=0,en=n-1;
    while(st<=en)
    {
        int mid=(st+en)/2.0;
        if(input[mid]==val)
        {
            return mid;
        }
        else if(input[mid]<val)
        {
            st=mid+1;
        }else 
        {
            en=mid-1;
        }
    }
    return -1;
}
int main()
{

	int size;
	cin >> size;
	int *input = new int[size];

	for(int i = 0; i < size; ++i)
	{
		cin >> input[i];
	}
	
	int t;
	cin >> t;

	while (t--)
	{
		int val;
		cin >> val;
		cout << binarySearch(input, size, val) << endl;
	}
	
	delete [] input;
	return 0;
}