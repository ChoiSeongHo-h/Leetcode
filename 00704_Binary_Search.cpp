"""
https://leetcode.com/problems/binary-search/
-> Accepted (Easy)
"""
  
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if(it == nums.end() || *it != target)
            return -1;

        return distance(nums.begin(), it);
    }
};
