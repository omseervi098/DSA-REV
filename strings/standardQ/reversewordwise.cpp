/*
Sample Input 1:

Welcome to Coding Ninjas

Sample Output 1:

Ninjas Coding to Welcome

*/
//one approach is to take another string and start from last character
#include<iostream>
#include<string.h>
void reverseStringWordWise(char input[]) {
    // o(n) time and o(n) space
    int len=strlen(input);
    char cpy[len+1];
    int j=len-1,k=0;
    for(int i=len-1;i>=-1;i--)
    {
        if(input[i]==' '||i<0)
        {
            for(int l=i+1;l<=j;l++)
            {
                cpy[k++]=input[l];
            }
            cpy[k++]=' ';
            j=i-1;
        }
    }
    for(int i=0;i<len;i++)
    {
        input[i]=cpy[i];
    }
}
//one approach is to reverse whole string than reverse each word
void reverseStringWordWise(char input[]) {
    //time o(n) space o(1)
    int len=strlen(input);
    char cpy[len+1];
    int j=len-1,k=0,i=0;
    while(i<j)
    {
        char temp=input[i];
        input[i]=input[j];
        input[j]=temp;
        i++;j--;
    }
    j=0;
    for(int i=0;i<=len;i++)
    {
        if(input[i]==' '||input[i]=='\0')
        {
            int en=i-1;
            while(j<en)
            {
                 char temp=input[j];
                 input[j]=input[en];
                 input[en]=temp;  
                j++;en--;
            }
            j=i+1;
        }
    }
}