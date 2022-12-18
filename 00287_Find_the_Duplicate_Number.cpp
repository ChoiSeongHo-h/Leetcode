"""
https://leetcode.com/problems/find-the-duplicate-number/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int tortoise_idx = 0;
        int hare_idx = 0;
        while(1)
        {
            tortoise_idx = nums[tortoise_idx];
            hare_idx = nums[nums[hare_idx]];
            if(tortoise_idx == hare_idx)
                break;
        }
        
        tortoise_idx = 0;
        while(1)
        {
            tortoise_idx = nums[tortoise_idx];
            hare_idx = nums[hare_idx];
            if(tortoise_idx == hare_idx)
                break;
        }

        return tortoise_idx;
    }
};
