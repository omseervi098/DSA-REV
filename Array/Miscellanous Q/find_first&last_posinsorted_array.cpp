class Solution {
public:
//here i searched for first occ using binary search and then for last occurence using binary
//o(logn)
//leetcode problem no 34
    vector<int> searchRange(vector<int>& nums, int target) {
        int st=0,end=nums.size()-1;
        int i=-1,j=-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(nums[mid]==target){
                 i=mid;
                 end=mid-1;
            }else if(nums[mid]>target){
                end=mid-1;
            }else
                st=mid+1;
        }st=0;end=nums.size()-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(nums[mid]==target){
                 j=mid;
                 st=mid+1;
            }else if(nums[mid]>target){
                end=mid-1;
            }else
                st=mid+1;
        }
        return {i,j};
    }
};