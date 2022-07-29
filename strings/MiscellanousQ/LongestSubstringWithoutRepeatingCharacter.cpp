//Bruteforce O(n^3)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkRepetition(s, i, j)) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }

    bool checkRepetition(string& s, int start, int end) {
        vector<int> chars(128);

        for (int i = start; i <= end; i++) {
            char c = s[i];
            chars[c]++;
            if (chars[c] > 1) {
                return false;
            }
        }

        return true;
    }
};
//we can also do using prefix sum in O(n^2)
//lastly we can use hashmap and do it in o(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int n=s.size();

        int mx=0,i=0,j;
        for( j=i;j<n;j++){
            if(freq.count(s[j])>0)
            {
                i=max(freq[s[j]],i);
            }
            mx=max(mx,j-i+1);
            freq[s[j]]=j+1;

        }
        return mx;
    }
};