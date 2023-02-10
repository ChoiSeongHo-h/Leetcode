"""
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
-> Accepted (Medium)
"""

class Solution 
{
public:
    int sz;
    vector<int> buy_tb;
    vector<int> sell_tb;
    vector<int> pass_tb0;
    vector<int> pass_tb1;

    int buy(vector<int>& prices, int fee, int idx, int stock_idx)
    {
        if(idx == sz)
            return 0;

        if(buy_tb[idx] != INT_MIN)
            return buy_tb[idx];
        
        int pass_next = -prices[idx] + pass(prices, fee, idx+1, idx);
        int sell_next = -prices[idx] + sell(prices, fee, idx+1, idx);
        buy_tb[idx] = max(pass_next, sell_next);
        return buy_tb[idx];
    }

    int pass(vector<int>& prices, int fee, int idx, int stock_idx)
    {
        if(idx == sz)
            return 0;

        if(stock_idx == -1)
        {
            if(pass_tb0[idx] != INT_MIN)
                return pass_tb0[idx];

            int pass_next = pass(prices, fee, idx+1, stock_idx);
            int buy_next = buy(prices, fee, idx+1, stock_idx);
            pass_tb0[idx] = max(pass_next, buy_next);
            return pass_tb0[idx];
        }
        else
        {
            if(pass_tb1[idx] != INT_MIN)
                return pass_tb1[idx];

            int pass_next = pass(prices, fee, idx+1, stock_idx);
            int sell_next = sell(prices, fee, idx+1, stock_idx);
            pass_tb1[idx] = max(pass_next, sell_next);
            return pass_tb1[idx];
        }
    }

    int sell(vector<int>& prices, int fee, int idx, int stock_idx)
    {
        if(idx == sz)
            return 0;

        if(sell_tb[idx] != INT_MIN)
            return sell_tb[idx];

        int pass_next = prices[idx] - fee + pass(prices, fee, idx+1, -1);
        int buy_next = prices[idx] - fee + buy(prices, fee, idx+1, -1);
        sell_tb[idx] = max(pass_next, buy_next);
        return sell_tb[idx];
    }

    int maxProfit(vector<int>& prices, int fee) 
    {
        sz = prices.size();
        buy_tb = vector<int>(sz, INT_MIN);
        sell_tb = vector<int>(sz, INT_MIN);
        pass_tb0 = vector<int>(sz, INT_MIN);
        pass_tb1 = vector<int>(sz, INT_MIN);

        int buy_first = buy(prices, fee, 0, -1);
        int pass_first = pass(prices, fee, 0, -1);
        return max(buy_first, pass_first);
    }
};
