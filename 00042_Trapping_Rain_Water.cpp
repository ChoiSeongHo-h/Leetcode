/*
https://leetcode.com/problems/trapping-rain-water/
-> Accepted (Hard)
*/

class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int sz = height.size();
        int h = 0;
        vector<int> l2r(sz);
        for(int i = 0; i<sz; ++i)
        {
            if(height[i] >= h)
                h = height[i];

            l2r[i] = h-height[i];
        }

        vector<int> r2l(sz);
        h = 0;
        for(int i = sz-1; i>=0; --i)
        {
            if(height[i] >= h)
                h = height[i];

            r2l[i] = h-height[i];
        }

        int ans = 0;
        for(int i = 0; i<sz; ++i)
            ans += min(r2l[i], l2r[i]);
        
        return ans;
    }
};
