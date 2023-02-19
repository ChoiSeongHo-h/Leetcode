"""
https://leetcode.com/problems/132-pattern/
-> Accepted (Medium)
"""
  
// O(logN)
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

// using stack, O(N)
class Solution 
{
public:
    bool find132pattern(vector<int>& nums) 
    {
        int sz = nums.size();
        if(sz<3)
            return false;

        stack<int> s;
        vector<int> mins(sz);
        mins[0] = nums[0];

        for(int i = 1; i<sz; ++i) 
            mins[i] = min(mins[i - 1], nums[i]);

        for(int i = sz-1; i>0; --i)
        {
            if(nums[i] <= mins[i])
                continue;

            while(!s.empty() && s.top() <= mins[i])
                s.pop();

            if(!s.empty() && s.top() < nums[i])
                return true;

            s.emplace(nums[i]);
        }

        return false;
    }
};
