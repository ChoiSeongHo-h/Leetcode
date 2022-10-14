/*
https://leetcode.com/problems/maximum-sum-circular-subarray/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int N = nums.size();
        if(N == 1)
            return nums[0];
        
        int local_maxima = nums[0];
        int global_maxima = nums[0];
        int local_minima = nums[0];
        int global_minima = nums[0];
        int acc = nums[0];
        int max_num = nums[0];
        bool has_pos = false;
        for(int i = 1; i<N; ++i)
        {
            local_maxima = max(nums[i], local_maxima+nums[i]);
            global_maxima = max(global_maxima, local_maxima);
            local_minima = min(nums[i], local_minima+nums[i]);
            global_minima = min(global_minima, local_minima);
            acc += nums[i];
            max_num = max(max_num, nums[i]);
            if(nums[i] > 0)
                has_pos = true;
        }
      
        if(!has_pos)
            return max_num;
        int ans = max(global_maxima, acc-global_minima);
        return ans;
    }
};
