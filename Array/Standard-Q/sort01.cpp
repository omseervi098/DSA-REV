#include <iostream>
#include <algorithm>
using namespace std;
//simplest one is to use sort function that take o(nlogn)
//another way is we can use two ptr one as start and other as endl this will take o(n)
void sort01(int* input,int n){
    // third way is to use nextzero ptr which will store upcoming address of zero
    //this also has o(n) time complexity
    int nzero=0;
    for(int i=0;i<n;i++){
        if(input[i]==0){
            swap(input[i],input[nzero]);
            nzero++;
        }
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

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		sort01(input, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}