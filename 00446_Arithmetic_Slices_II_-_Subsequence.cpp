/*
https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
-> Accepted (Hard)
*/

class Solution 
{
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int ans = 0;
        vector<unordered_map<long long, int>> dp(nums.size());
        for(int r = 1; r<nums.size(); ++r)
        {
            for(int l = 0; l<r; ++l)
            {
                long long gap = (long long)nums[r]-(long long)nums[l];
                auto it = dp[l].find(gap);
                if(it != dp[l].end())
                {
                    dp[r][gap] += it->second;
                    ans += it->second;
                }
                ++dp[r][gap];
            }
        }
        
        return ans;
    }
};
