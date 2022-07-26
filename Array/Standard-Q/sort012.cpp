#include <iostream>
#include <algorithm>
using namespace std;
void sort012(int *input, int n)
{
    // one method is we can use sorting it take o(nlogn)
    // another method is to take array of size n fill it accordingly it will take o(n) space and o(n) time
    //final is we can use two variable to store index of 0 and 2
    int nzero=0,ntwo=n-1;
    int st=0;
    while(st<=ntwo){
        if(input[st]==0)
            swap(input[st++],input[nzero++]);
        else if(input[st]==2)
            swap(input[st],input[ntwo--]);
        else
            st++;
    }

}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;

		cin >> size;
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		delete[] arr;
		cout << endl;
	}

	return 0;
}