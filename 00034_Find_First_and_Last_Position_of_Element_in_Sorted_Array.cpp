"""
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        auto it0 = lower_bound(nums.begin(), nums.end(), target);
        if(it0 == nums.end())
            return vector<int>{-1, -1};
        if(target != *it0)
            return vector<int>{-1, -1};

        auto it1 = upper_bound(nums.begin(), nums.end(), target);
        return vector<int>{(int)distance(nums.begin(), it0), (int)distance(nums.begin(), prev(it1))};    
    }
};
