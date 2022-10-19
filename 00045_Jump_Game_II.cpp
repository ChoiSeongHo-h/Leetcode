/*
https://leetcode.com/problems/jump-game-ii/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        int nSz = nums.size();
        vector<int> jumps(nSz, 10e5);
        jumps[0] = 0;
        if(nSz == 1)
            return 0;
        
        for(int i = 0; i < nSz-1; i++)
        {
            int jump = nums[i];
            for(int j = i+1; (j <= i+jump) && (j < nSz); j++)
            {
                jumps[j] = min(jumps[j], jumps[i]+1);
            }
        }

        
        return jumps.back();
    }
};
