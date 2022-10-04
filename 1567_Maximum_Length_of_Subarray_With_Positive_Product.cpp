/*
https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int getMaxLen(vector<int>& nums) 
    {
        int n_sz = nums.size();
        vector<int> l2r(n_sz);
        if(nums[0] < 0)
            ++l2r[0];
        for(int i = 1; i<n_sz; ++i)
        {
            if(nums[i] == 0)
                continue;
                
            if(nums[i] < 0)
                l2r[i] = l2r[i-1]+1;
            else 
                l2r[i] = l2r[i-1];
        }

        vector<int> r2l(n_sz);
        if(nums[n_sz-1] < 0)
            ++r2l[n_sz-1];
        for(int i = n_sz-2; i>=0; --i)
        {
            if(nums[i] == 0)
                continue;
                
            if(nums[i] < 0)
                r2l[i] = r2l[i+1]+1;
            else 
                r2l[i] = r2l[i+1];
        }
        
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i<n_sz; ++i)
        {
            if(nums[i] == 0)
            {
                cnt = 0;
                continue;
            }
            ++cnt;
            if(l2r[i] % 2 == 0)
                ans = max(ans, cnt);
        }

        cnt = 0;
        for(int i = n_sz-1; i>=0; --i)
        {
            if(nums[i] == 0)
            {
                cnt = 0;
                continue;
            }
            ++cnt;
            if(r2l[i] % 2 == 0)
                ans = max(ans, cnt);
        }
        
            
        return ans;
    }
};
