"""
https://leetcode.com/problems/single-number-iii/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int plane = nums[0];
        for(int i = 1; i<nums.size(); ++i)
            plane ^= nums[i];

        plane = plane & (-(long long)plane);

        vector<int> ans = {0, 0};
        for(int i = 0; i<nums.size(); ++i)
        {
            if((plane & nums[i]) == 0)
                ans[0] = ans[0]^nums[i];
            else
                ans[1] = ans[1]^nums[i];
        }
        
        return ans;
    }
};
