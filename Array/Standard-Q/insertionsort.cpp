#include <iostream>
using namespace std;

//O(n^2) best case sorted array --> o(n)
void insertionSort(int *input, int size)
{

    int pos=0,prev;
    for(int i=1;i<size;i++)
    {
        int j=i-1;
        prev=input[i];
        while(j>=0 && input[j]>prev)
        {
            input[j+1]=input[j];
            j--;
        }
        input[j+1]=prev; 
        
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
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		insertionSort(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		delete[] input;
		cout << endl;
	}

	return 0;
}