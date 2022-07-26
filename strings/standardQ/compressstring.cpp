/*
Sample Input 1:

aaabbccdsa

Sample Output 1:

a3b2c2dsa
*/
//one way is iterate whole string 
//and ever iteration cnt the freuency and then make left shift of all character
// this will take o(n^2) time and o(1) space 

//another way is to use another string and freq[256] arr to store frequency of each character
string getCompressedString(string &input) {
    // o(n) time but o(n) space
    int len=input.size();
    char a[len];
    int freq[256]={0};
    for(int i=0;i<len;i++)
    {
        int idx=(int)(input[i]);
        freq[idx]+=1;        
    }
    int k=0;
    for(int i=0;i<256;i++)
    {
        if(freq[i]>1)
        {
            a[k++]=(char)(i);
            a[k++]=(char)(freq[i]+'0');
        }else if(freq[i]==1)
        {
            a[k++]=(char)(i);
        }
    }a[k]='\0';
    a.erase(k,len);
    return a;
}
//another way which take o(n) time o(1) space
string getCompressedString(string &input) {
    // Write your code here.
    int len=input.size();
    char a[len];
    int i=0,j=0,count=0;
    while(j<=len)
    {
        if(input[j]==input[i])
        {
            count++;
            input[i] = input[j];
            j++;
        }else if(input[j]!=input[i])
        {
            if(count>1)
            {
                i++;
                input[i]=(char)(count+'0');
                 i++;
                input[i]=input[j];
            }else
            {
                i++;
                input[i]=input[j];
                
            }
            count=0;
        }
    }
    input.erase(i,j);
    return input;
}