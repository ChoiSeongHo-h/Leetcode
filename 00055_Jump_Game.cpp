/*
https://leetcode.com/problems/jump-game/
-> Accepted (Medium)
*/

class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int reach = nums[0];
        //1ro
        int sz = nums.size();
        for(int i = 0; i<sz; ++i)
        {
            if(i > reach)
                return false;
            
            reach = max(reach, i + nums[i]);
        }    
        
        return true;
    }
};
