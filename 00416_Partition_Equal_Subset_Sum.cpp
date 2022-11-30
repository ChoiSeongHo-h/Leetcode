/*
https://leetcode.com/problems/partition-equal-subset-sum/
-> Accepted (Medium)
*/

class Solution 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        int all = accumulate(nums.begin(), nums.end(), 0);
        if(all%2 == 1)
            return false;
        
        int target = all/2;
        vector<vector<int>> tb(nums.size()+1, vector<int>(target+1, 0));
        for(int i = 1; i<tb.size(); ++i)
        {
            if(nums[i-1] > target)
                for(int j = 1; j<tb[0].size(); ++j)
                    tb[i][j] = tb[i-1][j];
            if(nums[i-1] == target)
                return true;

            for(int sub_target = 1; sub_target<tb[0].size(); ++sub_target)
            {
                int candidate0 = tb[i-1][sub_target];
                if(sub_target-nums[i-1] < 0)
                {
                    tb[i][sub_target] = candidate0;
                    continue;
                }

                int candidate1 = tb[i-1][sub_target-nums[i-1]]+nums[i-1];
                if(candidate1 == target)
                    return true;

                tb[i][sub_target] = max(candidate0, candidate1);
            }
        }

        return false;
    }
};
