"""
https://leetcode.com/problems/132-pattern/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    bool find132pattern(vector<int>& nums) 
    {
        int sz = nums.size();
        if(sz < 3)
            return false;
      
        vector<int> l2r(sz);
        l2r[1] = nums[0];
        for(int i = 2; i<sz; ++i)
            l2r[i] = min(l2r[i-1], nums[i-1]);

        set<int> check;
        check.emplace(nums[sz-1]);
        for(int i = sz-2; i>=1; --i)
        {
            bool aleady_has = false;
            if(check.find(l2r[i]) == check.end())
                check.emplace(l2r[i]);
            else
                aleady_has = true;
            
            auto it = next(check.find(l2r[i]));

            if(it != check.end() && l2r[i] < nums[i] && *it < nums[i] && l2r[i] < *it)
                    return true;
            
            if(!aleady_has)
                check.erase(prev(it));
            check.emplace(nums[i]);
        }

        return false;
    }
};
