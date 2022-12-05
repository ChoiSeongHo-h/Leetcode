"""
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int sz = nums.size();
        if(sz == 1)
            return 0;

        vector<int> tb_l2r(sz);
        tb_l2r[0] = nums[0];
        bool all_ok = true;
        for(int i = 1; i<sz; ++i)
        {
            tb_l2r[i] = max(nums[i], tb_l2r[i-1]);
            if(nums[i-1] > nums[i])
                all_ok *= false;
        }
        if(all_ok)
            return 0;

        vector<int> tb_r2l(sz);
        tb_r2l[sz-1] = nums[sz-1];
        for(int i = sz-2; i>=0; --i)
            tb_r2l[i] = min(nums[i], tb_r2l[i+1]);

        int left_idx = 0;
        for(int i = 0; i<sz; ++i)
        {
            if(nums[i] != tb_r2l[i])
            {
                left_idx = i;
                break;
            }
        }
        int right_idx = sz-1;
        for(int i = sz-1; i>=0; --i)
        {
            if(nums[i] != tb_l2r[i])
            {
                right_idx = i;
                break;
            }
        }

        return right_idx-left_idx+1;
    }
};
