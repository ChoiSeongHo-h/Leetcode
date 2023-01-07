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
        
        vector<array<int, 2>> nonzeroIntervals;
        for(int i = 0; i<idcs0.size()-1; i++)
        {
            int iIdx = idcs0[i]+1;
            int fIdx = idcs0[i+1];
            if(iIdx == fIdx)
                continue;
            
            nonzeroIntervals.emplace_back(array<int, 2>{iIdx, fIdx});
        }
        
        vector<array<int, 2>> posIntervals;
        for(auto& nonzeroInterval : nonzeroIntervals)
        {
            int negCnt = 0;
            int lIdx = nonzeroInterval[1];
            int rIdx = nonzeroInterval[0];
            
            for(int i = nonzeroInterval[0]; i<nonzeroInterval[1]; i++)
            {
                if(nums[i] > 0)
                    continue;
                
                ++negCnt;
                lIdx = min(lIdx, i);
                rIdx = max(rIdx, i);
            }
            
            if(negCnt%2 == 0)
                posIntervals.emplace_back(nonzeroInterval);
            else
            {
                if(nonzeroInterval[0] != rIdx)
                    posIntervals.emplace_back(array<int, 2>{nonzeroInterval[0], rIdx});
                if(lIdx+1 != nonzeroInterval[1])
                    posIntervals.emplace_back(array<int, 2>{lIdx+1, nonzeroInterval[1]});
            }
        }
        
        int ans = 0;
        for(auto& posInterval : posIntervals)
        {
            int product = 1;
            for(int i = posInterval[0]; i<posInterval[1]; ++i)
                product *= nums[i];

            ans = max(ans, product);
        }
        
        return ans;
    }
};

