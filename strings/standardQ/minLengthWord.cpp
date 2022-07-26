/*
Sample Input 2 :

abc de ghihjk a uvw h j

Sample Output 2 :

a

*/
// o(n)time  o(1)space
#include<cstring>
void minLengthWord(char input[], char output[]){
		
	int len = strlen(input);
    int si = 0, ei = 0;
    int min_length = len, min_start_index = 0;
    while (ei <= len)
    {
        if (ei < len && input[ei] != ' ')
            ei++;
         
        else
        {
           
            int curr_length = ei - si;
         
            if (curr_length < min_length) 
            {
                min_length = curr_length;
                min_start_index = si;
            }
          
	      ei++;
          si=ei;
        }
      
        
    }
 for(int i=0;i<min_length;i++)
 {
   output[i]=input[min_start_index++];
 }
}

