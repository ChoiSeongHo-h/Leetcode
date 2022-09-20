/*
https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int nSz = nums.size();
        while(left < right)
        {
            int mid = (left+right)/2;
            int lim = maxOperations;
            for(int i = 0; i<nSz; i++)
            {
                if(nums[i] <= mid)
                    continue;
                
                lim -= (nums[i]-1) / mid;
            }
            if(lim >= 0)
                right = mid;
            else
                left = mid+1;
        }
        
        return left;
    }
};
