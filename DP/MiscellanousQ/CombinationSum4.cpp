/*
377. Combination Sum IV
Medium

Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.
*/
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        ans=[0]*(target+1)
        ans[0]=1
        for i in range(target+1):
            for num in nums:
                if i-num >= 0:
                    ans[i]+=ans[i-num]
        return ans[-1]