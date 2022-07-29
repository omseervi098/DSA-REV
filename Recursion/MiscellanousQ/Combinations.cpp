//Recursive time O(Nck)
class Solution {
public:
    void helper(vector<int> &v,vector<vector<int>> & ans,int n,int k,int i){
        if(k==0)
        {
            ans.push_back(v);
            return;
        }
        while(i<=n and k>0){
            v.push_back(i);
            k--;
            helper(v,ans,n,k,i+1);
            v.pop_back();
            k++;i++;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        helper(v,ans,n,k,1);
        return ans;
    }
};