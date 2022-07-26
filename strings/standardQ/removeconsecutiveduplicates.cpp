/*
Example:

Input String: "aaaa"
Expected Output: "a"

Input String: "aabbbcc"
Expected Output: "abc"

*/
void removeConsecutiveDuplicates(char input[]) {
    int j=1;
    char c=input[0];
    for(int i=1;input[i]!=0;i++)
    {
        if(input[i]!=c)
        {
            c=input[i];
            input[j++]=input[i];
        }
    }
    input[j]='\0';
}