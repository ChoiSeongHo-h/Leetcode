/*
https://leetcode.com/problems/maximum-product-subarray/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        int nSz = nums.size();
        if(nSz == 1)
            return nums[0];
        
        vector<int> idcs0;
        idcs0.emplace_back(-1);
        for(int i = 0; i<nSz; ++i)
        {
            if(nums[i] == 0)
                idcs0.emplace_back(i);
        }
        idcs0.emplace_back(nSz);
        
        vector<array<int, 2>> zIntervals;
        for(int i = 0; i<idcs0.size()-1; i++)
        {
            int iIdx = idcs0[i]+1;
            int fIdx = idcs0[i+1];
            if(iIdx == fIdx)
                continue;
            
            zIntervals.emplace_back(array<int, 2>{iIdx, fIdx});
        }
        
        vector<array<int, 2>> cIntervals;
        for(auto& zInterval : zIntervals)
        {
            int negCnt = 0;
            int lIdx = zInterval[1];
            int rIdx = zInterval[0];
            
            for(int i = zInterval[0]; i<zInterval[1]; i++)
            {
                if(nums[i] > 0)
                    continue;
                
                ++negCnt;
                lIdx = min(lIdx, i);
                rIdx = max(rIdx, i);
            }
            
            if(negCnt%2 == 0)
            {
                cIntervals.emplace_back(zInterval);
            }
            else
            {
                if(zInterval[0] != rIdx)
                    cIntervals.emplace_back(array<int, 2>{zInterval[0], rIdx});
                if(lIdx+1 != zInterval[1])
                    cIntervals.emplace_back(array<int, 2>{lIdx+1, zInterval[1]});
            }
        }
        
        int ans = 0;
        for(auto& cInterval : cIntervals)
        {
            int cross = 1;
            for(int i = cInterval[0]; i<cInterval[1]; ++i)
            {
                cross *= nums[i];
            }
            ans = max(ans, cross);
        }
        
        
        
        return ans;
    }
};
