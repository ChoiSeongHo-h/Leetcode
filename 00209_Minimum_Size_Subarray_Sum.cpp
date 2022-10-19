/*
https://leetcode.com/problems/minimum-size-subarray-sum/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        vector<int> acc_sum(nums.size()+1);
        acc_sum[0] = 0;
        for(int i = 1; i<nums.size()+1; ++i)
        {
            if(nums[i-1] >= target)
                return 1;
            acc_sum[i] = acc_sum[i-1]+nums[i-1];
        }
        if(acc_sum.back() < target)
            return 0;
        
        int len_lower = 2;
        int len_upper = nums.size();
        int succ_lower = nums.size();
        while(len_lower < len_upper)
        {
            int len = (len_lower+len_upper)/2;
            bool is_long = false;
            for(int i = 0; i<acc_sum.size()-len; ++i)
            {
                int consq_sum = acc_sum[i+len] - acc_sum[i];
                if(consq_sum >= target)
                {
                    succ_lower = min(succ_lower, len);
                    is_long = true;
                }
            }
            
            if(is_long)
                len_upper = len;
            else
                len_lower = len+1;
        }
        
        return succ_lower;
    }
};
