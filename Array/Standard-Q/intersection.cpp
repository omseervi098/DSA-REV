#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
// finding intersection between two array
void intersection(int *input1, int *input2, int size1, int size2)
{
    //  O(n^2)
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
        {
            if(input1[i]==input2[j])
            {
                cout<<input2[j]<<" ";
                input2[j]=-9999999;
                break;
            }
        }
    }
}
void intersection1(int *input1, int *input2, int size1, int size2){
    //O(size1*log(size1)+size2*log(size2))
   sort(input1,input1+size1);
   sort(input2,input2+size1);
   int i=0,j=0;
   while(i < size1 and j < size2){
        if(input1[i]<input2[j])
        i++;
        else if(input2[j]<input1[i])
        j++;
        else
        {
            cout<<input1[i]<<endl;
            i++;j++;
        }
   }
}
// we can also use hashmaps o store frequency of each element from input1 then while traversing input2 we can decrement cnt of element of input1 in hashmap
// that will also take O(size1+size2) with space of O(1)
void intersection2(int * input1,int * input2,int size1,int size2){
    unordered_map<int,int> map1;
    for(int i=0;i<size1;i++){
        map1[input1[i]]+=1;
    }
    for(int i=0;i<size2;i++){
        if(map1.count(input2[i])>0){
            cout<<input2[i]<<" ";
            map1[input1[i]]-=1;
            if(map1[input1[i]]==0)
            map1.erase(input2[i]);
        }
    }
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection2(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}