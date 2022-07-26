#include <iostream>
#include <cstring>
using namespace std;

void trimSpaces(char input[]) {
    // bruteforce o(n^2)time
    int n=strlen(input); 
    for(int i = 0; i < n;i++){
        if(input[i]==' '){
            for(int j=i;j<n-1;j++){
                input[j]=input[j+1];
            }
            input[n-1]='\0';
        }
    }
}
void trimSpaces1(char input[]) {
    // o(n) time
    int n=strlen(input),j=0;
    for(int i = 0; i < n;i++){
        if(input[i]!=' '){
            input[j++]=input[i];
        }
    }
    input[j]='\0';
}

int main() {
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces1(input);
    cout << input << endl;
}

