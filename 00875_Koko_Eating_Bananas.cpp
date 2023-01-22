"""
https://leetcode.com/problems/koko-eating-bananas/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int sz = piles.size();
        int lower = 1;
        int upper = *max_element(piles.begin(), piles.end())+1;
        while(lower < upper)
        {
            int rate = (lower+upper)/2;
            int time = 0;
            int num_piles = piles.size();
            for(int i = 0; i<num_piles; ++i)
                time += piles[i]/rate+int(bool(piles[i]%rate));

            if(time > h)
                lower = rate+1;
            else
                upper = rate;
        }
        
        return lower;
    }
};
