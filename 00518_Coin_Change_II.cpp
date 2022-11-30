/*
https://leetcode.com/problems/coin-change-ii/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<unordered_map<int, int>> dp;
    int search(int val, int max_coin, vector<int>& coins)
    {
        if(val < 0)
            return 0;
        if(val == 0)
            return 1;

        int partial = 0;
        for(int i = 0; i<coins.size(); ++i)
        {
            if(coins[i] > max_coin)
                break;

            if(dp[val].find(coins[i]) == dp[val].end())
                dp[val].emplace(coins[i], search(val-coins[i], coins[i], coins));
            partial += dp[val][coins[i]];
        }

        return partial;
    }
    int change(int amount, vector<int>& coins) 
    {
        if(amount == 0)
            return 1;
        dp = vector<unordered_map<int, int>>(amount+1);
        sort(coins.begin(), coins.end());
        int ans = 0;
        for(int i = 0; i<coins.size(); ++i)
            ans += search(amount-coins[i], coins[i], coins);

        return ans;
    }
};
