/*
https://leetcode.com/problems/target-sum/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<vector<int>> dp;
    int tot;

    int search(vector<int>& nums, int target, int idx, int acc)
    {
        if(idx == nums.size())
            return acc == target;
        
        int next0 = acc+nums[idx] + tot;
        if(dp[idx][next0] == -9999)
            dp[idx][next0] = search(nums, target, idx + 1, next0 - tot);
        int next1 = acc - nums[idx] + tot;
        if(dp[idx][next1] == -9999)
            dp[idx][next1] = search(nums, target, idx + 1, next1 - tot);
        return dp[idx][next0] + dp[idx][next1];
    }

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        tot = abs(accumulate(nums.begin(), nums.end(), 0));
        dp = vector<vector<int>>(nums.size(), vector<int>(2*tot+1, -9999));
        int ans = search(nums, target, 0, 0);
        return ans;
    }
};
