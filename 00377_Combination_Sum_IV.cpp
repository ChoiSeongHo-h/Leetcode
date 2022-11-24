/*
https://leetcode.com/problems/generate-parentheses/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<uint32_t> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 0; i<dp.size(); ++i)
        {
            for(int j = 0; j<nums.size(); ++j)
            {
                int prev = i-nums[j];
                if(prev<0)
                    continue;
                    
                dp[i] += dp[prev];
            }
        }

        return dp[target];
    }
};
