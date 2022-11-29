/*
https://leetcode.com/problems/maximum-subarray/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int global_maxima = nums[0];
        int local_maxima = nums[0];
        for(int i = 1; i<nums.size(); ++i)
        {
            int candidate = nums[i];
            local_maxima = max(candidate, local_maxima + nums[i]);
            global_maxima = max(global_maxima, local_maxima);
        }

        return global_maxima;
    }
};
