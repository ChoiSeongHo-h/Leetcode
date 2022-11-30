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
        
        vector<int> good_coins;
        for(auto i : coins)
        {
            if (i>amount)
                continue;
            
            good_coins.emplace_back(i);
        }
        int coins_sz = good_coins.size();
        
        queue<array<int, 2>> bfsQ;
        vector<int> emplaced(amount+1, 0);
        for(int i = 0; i<coins_sz; i++)
        {
            array<int, 2> input;
            input[0] = good_coins[i];
            input[1] = 1;
            bfsQ.emplace(input);
            emplaced[input[0]] = 1;
        }
        
        int ans = 10e4;
        while(!bfsQ.empty())
        {
            auto node = bfsQ.front();
            bfsQ.pop();
            
            if(node[0] == amount)
                return node[1];
            
            for(int i = 0; i<coins_sz; i++)
            {
                array<int, 2> next;
                next[0] = node[0] + good_coins[i];
                if(next[0] > amount)
                    continue;

                next[1] = node[1] + 1;
                if(emplaced[next[0]] == 0)
                {
                    bfsQ.emplace(next);
                    emplaced[next[0]] = 1;
                }
            }
        }
        
        if(ans == 10e4)
            return -1;
            
        return ans;
    }
};
