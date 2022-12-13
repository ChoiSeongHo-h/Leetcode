/*
https://leetcode.com/problems/array-of-doubled-pairs/
-> Accepted (Medium)
*/

class Solution 
{
public:
    bool canReorderDoubled(vector<int>& arr) 
    {
        array<int, 100001> pNs{0, };
        array<int, 100001> nNs{0, };
        for(auto i : arr)
        {
            if(i>=0)
                pNs[i]++;
            
            if(i<0)
                nNs[-i]++;
        }

        if(pNs[0]%2 == 1)
            return false;
        
        for(int i = 1; i<=5e4; i++)
        {
            if(pNs[i] == 0)
                continue;
            
            if(pNs[i] > pNs[2*i])
                return false;
            else
                pNs[2*i] -= pNs[i];
        }
        for(int i = 1+5e4; i<=10e4; i++)
        {
            if(pNs[i] > 0)
                return false;
        }

        for(int i = 1; i<=5e4; i++)
        {
            if(nNs[i] == 0)
                continue;
            
            if(nNs[i] > nNs[2*i])
                return false;
            else
                nNs[2*i] -= nNs[i];
        }
        for(int i = 1+5e4; i<=10e4; i++)
        {
            if(nNs[i] > 0)
                return false;
        }
        
        return true;
    }
};
