/*
leetcode problem no 438
Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/
//bruteforce approach
//time o(s.size()*p.size())
//will get tle
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())
            return {};
        unordered_map<char,int> map;
        for(int i=0;i<p.size();i++){
            map[p[i]]+=1;
        }
        vector<int> ans;
        for(int j=0;j<s.size()-(p.size()-1);j++){
            bool check=false;
            unordered_map<char,int> fors;
             for(int k=j;k<(p.size()+j);k++){
                fors[s[k]]+=1;
            }
            for(int k=j;k<(p.size()+j);k++){
                    if(fors[s[k]]!=map[s[k]]){
                        check=false;
                        break;
                    }   
                if(map.count(s[k])>0){
                   check=true;
                    //map.erase(s[k]);
                }else{
                    check=false;
                    break;
                }
            }
            if(check){
                ans.push_back(j);
            }
        }
        return ans;
    }
};
//time o(s.size());
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())
            return {};
        vector<int> window(26);
        vector<int> freq_p(26);
        for(int i=0;i<p.size();i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }vector<int> ans;
        if(freq_p==window)ans.push_back(0);
        for(int i=p.size();i<s.size();i++){
            window[s[i-p.size()]-'a']--;
            window[s[i]-'a']++;
            if(window==freq_p)
                ans.push_back(i-p.size()+1);
            
        }return ans;
    }
};