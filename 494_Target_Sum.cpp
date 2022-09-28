/*
https://leetcode.com/problems/target-sum/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<int> numsG;
    int targetG;
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        numsG = nums;
        targetG = target;
        return GetAllCase(0, 0);
    }
    int GetAllCase(int idx, int acc)
    {
        if(idx == numsG.size()-1)
        {
            int s = acc+numsG[idx] == targetG;
            s += acc-numsG[idx] == targetG;
            return s;
        }
        
        return GetAllCase(idx+1, acc+numsG[idx]) + GetAllCase(idx+1, acc-numsG[idx]);
    }
};
