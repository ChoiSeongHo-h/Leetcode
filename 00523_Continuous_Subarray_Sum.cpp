/*
https://leetcode.com/problems/continuous-subarray-sum/
-> Accepted (Medium)
*/

class Solution 
{
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int sz = nums.size();
        if(sz == 1)
            return false;

        unordered_map<int, int> um;
        um.emplace(0, -1);
        int acc = 0;
        for(int i = 0; i<sz; ++i)
        {
            acc = (acc+nums[i])%k;
            auto it = um.find(acc);

            if(it != um.end() && i - it->second >= 2)
                return true;

            um.emplace(acc, i);
        }

        return false;
    }
};
