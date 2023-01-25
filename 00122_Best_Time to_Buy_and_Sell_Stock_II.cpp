"""
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    int sz = 0;
    vector<int> pass0_tb;
    vector<int> pass1_tb;
    vector<int> buy_tb;
    vector<int> sell_tb;
    int pass(vector<int>& prices, int idx, bool has)
    {
        if(idx == sz)
            return 0;

        if(has)
        {
            if(pass1_tb[idx] == -1)
                pass1_tb[idx] = max(sell(prices, idx+1, true), pass(prices, idx+1, true));
            return pass1_tb[idx];
        }

        if(pass0_tb[idx] == -1)
            pass0_tb[idx] = max(buy(prices, idx+1, false), pass(prices, idx+1, false));
        return pass0_tb[idx];
    }

    int buy(vector<int>& prices, int idx, bool has)
    {
        if(idx == sz)
            return 0;

        if(buy_tb[idx] == -1)
            buy_tb[idx] = -prices[idx] + max(sell(prices, idx+1, true), pass(prices, idx+1, true));
        return buy_tb[idx];
    }

    int sell(vector<int>& prices, int idx, bool has)
    {
        if(idx == sz)
            return 0;

        if(sell_tb[idx] == -1)
            sell_tb[idx] = prices[idx] + max(buy(prices, idx+1, false), pass(prices, idx+1, false));
        return sell_tb[idx];
    }

    int maxProfit(vector<int>& prices) 
    {
        sz = prices.size();
        pass0_tb = vector<int>(sz, -1);
        pass1_tb = vector<int>(sz, -1);
        buy_tb = vector<int>(sz, -1);
        sell_tb = vector<int>(sz, -1);

        int pass_profit = pass(prices, 0, false);
        int buy_profit = buy(prices, 0, false);
        return max(pass_profit, buy_profit);
    }
};
