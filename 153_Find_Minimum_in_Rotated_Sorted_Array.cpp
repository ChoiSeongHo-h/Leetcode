/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int sz = nums.size();
        if(sz == 1)
            return nums[0];
        
        int left = 0;
        int right = sz-1;
        while(left < right)
        {
            if(nums[left] < nums[right])
                return nums[left];
            
            int mid = (left+right)/2;
            if(nums[left] <= nums[mid])
                left = mid+1;
            else
                right = mid;
        }
        
        return nums[left];
    }
};
