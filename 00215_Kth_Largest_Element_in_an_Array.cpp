/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int global_min = 1000000;
        int global_max = -1000000;
        for(int i = 0; i<nums.size(); ++i)
        {
            global_min = min(global_min, nums[i]);
            global_max = max(global_max, nums[i]);
        }
      
        vector<int> hist(global_max-global_min+1, 0);
        for(int i = 0; i<nums.size(); ++i)
            ++hist[nums[i]-global_min];
      
        int cnt = 0;
        for(int i = hist.size()-1; i>=0; --i)
        {
            cnt += hist[i];
            if(cnt >= k)
                return i+global_min;
        }
      
        return 0;
    }
};
