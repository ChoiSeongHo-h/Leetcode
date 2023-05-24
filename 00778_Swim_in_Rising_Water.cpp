/*
https://leetcode.com/problems/swim-in-rising-water/
-> Accepted (Hard)
*/

// priority queue
class Solution 
{
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        vector<int> dx{-1, 0, 0, 1};
        vector<int> dy{0, -1, 1, 0};
        int n = grid.size();
      
        map<int, vector<int>> pq;
        pq.emplace(grid[n-1][n-1], vector<int>{n-1, n-1});
        grid[n-1][n-1] += 100000;
        int ans = -1;
        while(!pq.empty())
        {
            auto now = pq.begin();
            int val = now->first;
            int y = now->second[0];
            int x = now->second[1];
            pq.erase(now);

            ans = max(ans, val);
            if(y == 0 && x == 0)
                break;

            for(int i = 0; i<4; ++i)
            {
                int next_x = x+dx[i];
                int next_y = y+dy[i];
                if(next_x != -1 && next_x != n && next_y != -1 && next_y != n && grid[next_y][next_x] < 10000)
                {
                    pq.emplace(grid[next_y][next_x], vector<int>{next_y, next_x});
                    grid[next_y][next_x] += 100000;
                }
            }
        }
        
        return ans;
    }
};
