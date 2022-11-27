/*
https://leetcode.com/problems/perfect-squares/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int numSquares(int n) 
    {
        int init = 1;
        vector<int> nodes;
        while(1)
        {
            int sq = init*init; 
            if(n < init*init)
                break;

            nodes.emplace_back(sq);
            init++;
        }

        vector<int> dp(n+1, n);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i<dp.size(); ++i)
        {
            for(int j = 0; j<nodes.size(); ++j)
            {
                int node = nodes[j];
                if(i-node < 0)
                    continue;

                dp[i] = min(dp[i], dp[i-node]+1);
            }
        }

        return dp.back();
    }
};
