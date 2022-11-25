/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<int> buy_tb;
    vector<int> pass0_tb;
    vector<int> pass1_tb;
    vector<int> sell_tb;

    int buy(vector<int>& prices, int idx, bool has)
    {
        if(idx == prices.size())
            return 0;

        if(buy_tb[idx] == -1)
            buy_tb[idx] = -prices[idx] + max(pass(prices, idx+1, true), sell(prices, idx+1, true));

        return buy_tb[idx];
    }

    int pass(vector<int>& prices, int idx, bool has)
    {
        if(idx == prices.size())
            return 0;

        if(has)
        {
            if(pass1_tb[idx] == -1)
                pass1_tb[idx] = max(pass(prices, idx+1, true), sell(prices, idx+1, true));
            
            return pass1_tb[idx];
        }
        else
        {
            if(pass0_tb[idx] == -1)
                pass0_tb[idx] = max(pass(prices, idx+1, false), buy(prices, idx+1, false));
            
            return pass0_tb[idx];
        }
    }

    int sell(vector<int>& prices, int idx, bool has)
    {
        if(idx == prices.size())
            return 0;

        if(sell_tb[idx] == -1)
            sell_tb[idx] = prices[idx] + pass(prices, idx+1, false);
        
        return sell_tb[idx];
    }

    int maxProfit(vector<int>& prices) 
    {
        int sz = prices.size();
        buy_tb = vector<int>(sz, -1);
        pass0_tb = vector<int>(sz, -1);
        pass1_tb = vector<int>(sz, -1);
        sell_tb = vector<int>(sz, -1);

        int buy_val = buy(prices, 0, false);
        int pass_val = pass(prices, 0, false);
        return max(buy_val, pass_val);
    }
};
