/*
https://leetcode.com/problems/cherry-pickup-ii/
-> Accepted (Hard)
*/

class Solution 
{
public:
    int h;
    int w;
    vector<vector<vector<int>>> dp;

    int find_ans(int i, int j0, int j1, vector<vector<int>>& grid)
    {
        if(j0 == -1 || j0 == w || j1 == -1 || j1 == w)
            return 0;

        if(dp[i][j0][j1] != -1)
            return dp[i][j0][j1];

        int val_now = 0;
        if(j0 == j1)
            val_now = grid[i][j0];
        else
            val_now = grid[i][j0] + grid[i][j1];

        if(i == h-1)
        {
            dp[i][j0][j1] = val_now;
            return val_now;
        }

        int val_next = -1;
        for(int idx0 = -1; idx0<=1; ++idx0)
        {
            for(int idx1 = -1; idx1<=1; ++idx1)
                val_next = max(val_next, find_ans(i+1, j0+idx0, j1+idx1, grid));
        }

        dp[i][j0][j1] = val_now+val_next;
        return val_now+val_next;
    }

    int cherryPickup(vector<vector<int>>& grid) 
    {
        h = grid.size();
        w = grid[0].size();
        dp = vector<vector<vector<int>>>(h, vector<vector<int>>(w, vector<int>(w, -1)));
        int ans = find_ans(0, 0, grid[0].size()-1, grid);
        return ans;
    }
};
