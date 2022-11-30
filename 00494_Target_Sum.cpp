/*
https://leetcode.com/problems/target-sum/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<vector<int>> dp;

    int search(vector<int>& nums, int target, int idx, int acc)
    {
        if(idx == nums.size())
            return acc == target;
        
        int next0 = acc+nums[idx]+1000;
        if(dp[idx][next0] == -9999)
            dp[idx][next0] = search(nums, target, idx+1, next0-1000);
        int next1 = acc-nums[idx]+1000;
        if(dp[idx][next1] == -9999)
            dp[idx][next1] = search(nums, target, idx+1, next1-1000);
        return dp[idx][next0]+dp[idx][next1];
    }

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        dp = vector<vector<int>>(nums.size(), vector<int>(2001, -9999));
        return search(nums, target, 0, 0);
    }
};
