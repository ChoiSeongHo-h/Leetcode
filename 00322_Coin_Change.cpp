/*
https://leetcode.com/problems/coin-change/
-> Accepted (Medium)
*/

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if(amount == 0)
            return 0;
        
        vector<int> cs;
        for(auto i : coins)
        {
            if (i>amount)
                continue;
            
            cs.emplace_back(i);
        }
        int cSz = cs.size();
        
        queue<array<int, 2>> bfsQ;
        unordered_map<int, int> emplaced;
        for(int i = 0; i<cSz; i++)
        {
            array<int, 2> input;
            input[0] = cs[i];
            input[1] = 1;
            bfsQ.emplace(input);
            emplaced.emplace(input[0], input[1]);
        }
        
        int ans = 10e4;
        while(!bfsQ.empty())
        {
            auto node = bfsQ.front();
            bfsQ.pop();
            
            
            if(node[0] > amount)
                continue;
            
            if(node[0] == amount)
                ans = min(ans, node[1]);
            
            for(int i = 0; i<cSz; i++)
            {
                array<int, 2> next;
                next[0] = node[0] + cs[i];
                next[1] = node[1] + 1;
                if(emplaced.find(next[0]) == emplaced.end() || emplaced[next[0]] > next[1])
                {
                    bfsQ.emplace(next);
                    emplaced.emplace(next[0], next[1]);
                }
            }
            
        }
        
        if(ans == 10e4)
            return -1;
            
        return ans;
    }
};
