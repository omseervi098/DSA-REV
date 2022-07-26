/*
leetcode problem no 6
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
*/
//bruteforce we can take 2d charracter array
class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows,vector<char>(s.size(),'0'));
        string str="";
        int k=0,col=0;
        while(k<s.size()){
            int i=0;
            for(i=0;i<numRows and k<s.size();i++){
                v[i][col]=s[k++];
            }
            col++;i-=2;
            if(k==s.size())break;
            int j=col;
            for(;i>=1 and j<(col+numRows-1) and k<s.size();i--,j++){
                v[i][j]=s[k++];
            }
            col=j;
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]!='0')
                    str+=v[i][j];
            }
        }
        return str;
    }
};
//better optimised solution
// space o(n) time o(n)
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)return s;
       string temp="";
        vector<string> dp(numRows,"");
        for(int i=0,row=0,step=1;i<s.size();i++){
            dp[row]+=s[i];
            if(row==0) step=1;
            else if(row==numRows-1) step=-1;
            row+=step;
        }
        for(auto it:dp)
            temp+=it;
        return temp;
    }
};