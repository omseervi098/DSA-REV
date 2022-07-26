#include<unordered_map>
#include<climits>
void printIntersection(int input1[], int input2[], int size1, int size2) {
    unordered_map<int,int> m1 ;
    //time o(n)  and space o(1)
    for(int i=0 ;i<size1 ;i++)
         m1[input1[i]]++;
    
    for(int i=0 ;i<size2 ;i++)
    {
        if(m1[input2[i]]>0)
        {
            cout<<input2[i]<<endl;
            m1[input2[i]]--;  
        }
            
    }
    
}
