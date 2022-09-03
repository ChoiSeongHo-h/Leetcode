/*
https://leetcode.com/problems/array-of-doubled-pairs/
-> Accepted (Medium)
*/

class Solution 
{
public:
    bool canReorderDoubled(vector<int>& arr) 
    {
        vector<int> pNs(1+10e5, 0);
        vector<int> nNs(1+10e5, 0);
        for(auto i : arr)
        {
            if(i>=0)
                pNs[i]++;
            
            if(i<0)
                nNs[-i]++;
        }

        
        for(int i = 1; i<=5e5; i++)
        {
            if(pNs[i] == 0)
                continue;
            
            if(pNs[i] > pNs[2*i])
                return false;
            else
            {
                pNs[2*i] -= pNs[i];
                pNs[i] = 0;
            }
        }
        for(int i = 1+5e5; i<=10e5; i++)
        {
            if(pNs[i] > 0)
                return false;
        }
        
        for(int i = 1; i<=5e5; i++)
        {
            if(nNs[i] == 0)
                continue;
            
            if(nNs[i] > nNs[2*i])
                return false;
            else
            {
                nNs[2*i] -= nNs[i];
                nNs[i] = 0;
            }
        }
        for(int i = 1+5e5; i<=10e5; i++)
        {
            if(nNs[i] > 0)
                return false;
        }
        
        if(pNs[0]&1)
            return false;
        
        return true;
    }
};
