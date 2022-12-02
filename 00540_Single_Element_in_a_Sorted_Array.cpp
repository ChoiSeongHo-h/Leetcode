"""
https://leetcode.com/problems/single-element-in-a-sorted-array/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int sz = nums.size();
        if(sz == 1)
            return nums[0];

        int left_idx = 0;
        if(nums[left_idx] == nums[left_idx+1])
            ++left_idx;
        else
            return nums[left_idx];
        int right_idx = nums.size()-1;
        if(nums[right_idx-1] != nums[right_idx])
            return nums[right_idx];

        while(left_idx < right_idx)
        {
            int mid_idx = (left_idx+right_idx)/2;
            if(nums[mid_idx-1] != nums[mid_idx] && nums[mid_idx] != nums[mid_idx+1])
                return nums[mid_idx];
            if(nums[mid_idx] == nums[mid_idx+1])
                ++mid_idx;
            int strange = 0;
            if(mid_idx % 2 == 0)
                strange = 1;
            if(strange == 0)
                left_idx = mid_idx;
            else
                right_idx = mid_idx;
        }
        
        return nums[right_idx];
    }
};
