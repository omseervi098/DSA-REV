class Solution {
public:
    void permute(vector<int>& nums,vector<int> output,vector<vector<int>>&v) {
        if(nums.size()==0)
        {
            v.push_back(output);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            vector<int>cpy;
            cpy=nums;
            cpy.erase(cpy.begin()+i);
            output.push_back(nums[i]);
            permute(cpy,output,v);
            output.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> v;
        permute(nums,output,v);
        return v;
    }
};