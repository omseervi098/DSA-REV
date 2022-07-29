//Bruteforce checking every permutation O(N!)
class Solution {
    bool flag = false;
    
    bool checkInclusion(string s1, string s2) {
        permute(s1, s2, 0);
        return flag;
    }
    
    string swap(string s, int i0, int i1) {
        if (i0 == i1)
            return s;
        string s1 = s.substr(0, i0);
        string s2 = s.substr(i0 + 1, i1);
        string s3 = s.substr(i1 + 1);
        return s1 + s[i1] + s2 + s[i0] + s3;
    }
    
    void permute(string s1, string s2, int l) {
        if (l == s1.length()) {
            if (s2.indexOf(s1) >= 0)
                flag = true;
        } else {
            for (int i = l; i < s1.length(); i++) {
                s1 = swap(s1, l, i);
                permute(s1, s2, l + 1);
                s1 = swap(s1, l, i);
            }
        }
    }
};
//using sorting O(N*logn(n) +(M-N)*N*Log(N))
class Solution {
    boolean checkInclusion(String s1, String s2) {
        s1 = sort(s1);
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            string temp=sort(s2.substr(i, i + s1.length()));
            if (s1==temp)
                return true;
        }
        return false;
    }
    
    string sort(string s) {
        char[] t = s.toCharArray();
        Arrays.sort(t);
        return new string(t);
    }
};
//Optimised using sliding window O(N)
class Solution {
public:
    bool checkInclusion(string p, string s) {
        if(p.size()>s.size())
            return {};
        vector<int> window(26);
        vector<int> freq_p(26);
        for(int i=0;i<p.size();i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        if(freq_p==window)return true;
        for(int i=p.size();i<s.size();i++){
            window[s[i-p.size()]-'a']--;
            window[s[i]-'a']++;
            if(window==freq_p)
                return true;
            
        }return false;
        
    }
};