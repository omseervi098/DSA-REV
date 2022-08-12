/*
216. Combination Sum III
Medium

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

    Only numbers 1 through 9 are used.
    Each number is used at most once.

Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
*/
class Solution {
public:
     
   
     void combinationSum3(int k,int st,vector<int>&temp, int n,vector<vector<int>>&v) {
        if(temp.size()==k){
            if(n==0){
                v.push_back(temp);
                return;
            }else
                return;
        }
        for(int i=st;i<=9;i++){
            temp.push_back(i);
            combinationSum3(k,i+1,temp,n-i,v);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>>cpy;
        combinationSum3(k,1,temp,n,cpy);
        return cpy;
    }
};