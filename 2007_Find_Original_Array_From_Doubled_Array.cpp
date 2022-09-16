/*
https://leetcode.com/problems/find-original-array-from-doubled-array/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<int> findOriginalArray(vector<int>& changed) 
    {
        int cSz = changed.size();
        vector<int> empty;
        vector<int> ans;
        if(cSz == 0 || cSz%2 == 1)
            return empty;
            
        array<int, 100001> nNums = {0,};
        for(int i = 0; i<cSz; i++)
            ++nNums[changed[i]];
        
        if(nNums[0]%2 == 1)
            return empty;
            
        if(nNums[0] > 0)
        {
            for(int i = 0; i<nNums[0]/2; i++)
                ans.emplace_back(0);
        }
        
        for(int i = 1; i<=50000; i++)
        {
            if(nNums[i] == 0)
                continue;
            
            if(nNums[i] > nNums[2*i])
                return empty;
            
            nNums[2*i] -= nNums[i];
            for(int nNum = 0; nNum<nNums[i]; nNum++)
                ans.emplace_back(i);
        }
        
        for(int i = 50001; i<=100000; i++)
        {
            if(nNums[i] > 0)
                return empty;
        }
        
        return ans;
    }
};
