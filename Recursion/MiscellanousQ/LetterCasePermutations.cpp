class Solution {
public:
    void helper(string s,string out,vector<string> &v){
        if(s.size()==0){
            v.push_back(out);return;
        }
        if(isalpha(s[0])){
            string op1=out;
            op1+=tolower(s[0]);
            helper(s.substr(1),op1,v);
            string op2=out;
            op2+=toupper(s[0]);
            helper(s.substr(1),op2,v);
        }else{
            out+=s[0];
            helper(s.substr(1),out,v);
        }
        
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>v;
        helper(s,"",v);
        return v;
    }
};