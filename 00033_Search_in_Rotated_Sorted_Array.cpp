"""
https://leetcode.com/problems/search-in-rotated-sorted-array/
-> Accepted (Medium)
"""

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int sz = nums.size();
        if(sz == 1)
        {
            if(nums[0] == target)
                return 0;
            else
                return -1;
        }
            
        int left = 0;
        int right = sz;
        while(left<right)
        {
            int mid = (left + right)/2;
            if(nums[0] > nums[mid])
                right = mid;
            else
                left = mid+1;
        }
      
        if(target < nums[0])
        {
            auto it = lower_bound(nums.begin() + left % sz, nums.end(), target);
            if(it == nums.end())
                return -1;
            if(*it == target)
                return distance(nums.begin(), it);
            else
                return -1;
        }
        else
        {
            auto it = lower_bound(nums.begin(), nums.begin()+left, target);
            if(it == nums.end())
                return -1;
            if(*it == target)
                return distance(nums.begin(), it);
            else
                return -1;
        }

        return left;
    }
};
