"""
https://leetcode.com/problems/longest-increasing-subsequence/
-> Accepted (Medium)
"""

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> arr;
        arr.emplace_back(100000);
        for(int i = 0; i<nums.size(); ++i)
        {
            if(arr.back() < nums[i])
            {
                arr.emplace_back(nums[i]);
                continue;
            }
                
            auto it = lower_bound(arr.begin(), arr.end(), nums[i]);
            *it = min(*it, nums[i]);
        }

        return arr.size();
    }
};
