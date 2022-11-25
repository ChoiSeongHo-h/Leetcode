/*
https://leetcode.com/problems/house-robber/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<int> dp_steal;
    vector<int> dp_pass;
    int steal(vector<int>& nums, int idx)
    {
        if(idx == nums.size()-1)
            return nums[idx];

        if(dp_steal[idx] == -1)
            dp_steal[idx] = nums[idx]+pass(nums, idx+1);

        return dp_steal[idx];
    }

    int pass(vector<int>& nums, int idx)
    {
        if(idx == nums.size()-1)
            return 0;

        if(dp_pass[idx] == -1)
            dp_pass[idx] = max(steal(nums, idx+1), pass(nums, idx+1));
            
        return dp_pass[idx];
    }

    int rob(vector<int>& nums) 
    {
        dp_steal = vector<int>(nums.size(), -1);
        dp_pass = vector<int>(nums.size(), -1);
        int steal_first = steal(nums, 0);
        int pass_first = pass(nums, 0);
        return max(steal_first, pass_first);
    }
};
