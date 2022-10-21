"""
https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    int minOperations(vector<int>& nums, int x)
    {
        int sz = nums.size();
        if((x < nums[0]) && (x < nums[sz-1]))
            return -1;
        
        vector<int> l2r(sz);
        l2r[0] = nums[0];
        for(int i = 1; i<sz; ++i)
        {
            l2r[i] = nums[i] + l2r[i-1];
        }
        if(l2r[sz-1] < x)
            return -1;
        vector<int> r2l(sz);
        r2l[sz-1] = nums[sz-1];
        for(int i = sz-2; i>=0; --i)
        {
            r2l[i] = nums[i] + r2l[i+1];
        }

        int ans = 9999999;
        for(int i = 0; i<sz; ++i)
        {
            if(l2r[i] > x)
                break;
            
            if(l2r[i] == x)
            {
                ans = min(ans, i+1);
                continue;
            }
            int left_sum = l2r[i];
            int left_num = i+1;
            int left = i+1;
            int right = sz;
            while(left<right)
            {
                int mid = (left+right)/2;
                int right_sum_target = x-left_sum;
                if(r2l[mid] == right_sum_target)
                {
                    ans = min(ans, left_num + sz - mid);
                    break;
                }
                else if(r2l[mid] < right_sum_target)
                {
                    right = mid;
                    continue;
                }
                else
                {
                    left = mid+1;
                    continue;
                }
            }
        }
        int left = 0;
        int right = sz;

        while(left<right)
        {
            int mid = (left+right)/2;
            int right_sum_target = x;
            if(r2l[mid] == right_sum_target)
            {
                ans = min(ans, sz - mid);
                break;
            }
            else if(r2l[mid] < right_sum_target)
            {
                right = mid;
                continue;
            }
            else
            {
                left = mid+1;
                continue;
            }
        }
        
        if(ans == 9999999)
            ans = -1;
        
        return ans;
    }
};
