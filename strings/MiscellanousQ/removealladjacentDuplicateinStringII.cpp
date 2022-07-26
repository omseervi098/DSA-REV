/* leetcode problem no 1209 
Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.

Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
*/
//got stuck in hashmap solution for while
//after i tried another solution
//it time o(n*k) and space o(n)
//it gives tle
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> m;
        
        for(int i=0;i<s.size();i++){
            stack<char> h;
            h.push(s[i]);
            while(!m.empty() and m.top()==s[i]){
                 h.push(m.top());m.pop();
             }
             if(h.size()!=k){
                while(h.size()!=0){
                    m.push(h.top());m.pop();
                }
            } 
        }
        string tmp="";
        while(m.size()!=0){
            tmp+=m.top();m.pop();
        }
        reverse(tmp.begin(),tmp.end());
        return tmp;
    }
};
//instead of taking two stack we can use one stack which will have pair of character and its count
//this approach takes o(n) time and o(n) space
string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
          if(!st.empty() and st.top().first==s[i])
          {
              st.top().second++;
          }else
              st.push({s[i],1});
          if(st.top().second==k)
                  st.pop();              
        }
        string temp="";
        while(!st.empty()){
            while(st.top().second--){
                temp+=st.top().first;
            }
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }