/* leetcode problem no 38 
Example 1:

Input: n = 1
Output: "1"
Explanation: This is the base case.

Example 2:

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
*/
//recursive solution time o(n^2)
class Solution {
public:
    string helper(int n,int st){
        if(n==1)
            return "1";
        string sans=helper(n-1,st);
        string temp="";
        int j=0;
        if(sans.size()==1){
            temp+="1";
            temp+=sans[0];
            return temp;
        }
        for(int i=1;i<=sans.size();i++){
            if(sans[i]!=sans[j]){
                temp+="1";
                temp+=sans[j++];
                continue;
            }
            while(sans[i]==sans[j] and  i<sans.size()){
                i++;
            }
            temp+=(i-j)+'0';
            temp+=sans[j];
            j=i;
        }
        return temp;
    }
    string countAndSay(int n) {
        return helper(n,n);
    }
};
//iterative solution
class Solution {
public:
    string helper(int n){
        if(n==1)
            return "1";
        string sans="1";
        for(int k=0;k<n-1;k++){
            string temp="";
            cout<<sans<<endl;
            if(sans.size()==1){
                temp+="1";
                temp+=sans[0];
                sans=temp;
                continue;
             }
             int j=0;
             for(int i=1;i<=sans.size();i++){
                 if(sans[i]!=sans[j]){
                     temp+="1";
                     temp+=sans[j++];
                     
                     continue;
                  }
                  while(sans[i]==sans[j] and  i<sans.size()){
                      i++;
                  }
                  temp+=(i-j)+'0';
                  temp+=sans[j];
                  j=i;
             }sans=temp;
        }
        return sans;
    }
    string countAndSay(int n) {
        return helper(n);
    }
};