
"""
https://leetcode.com/problems/max-area-of-island/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    vector<int> dxs{-1, 0, 0, 1};
    vector<int> dys{0, 1, -1, 0};
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int h = grid.size();
        int w = grid[0].size();
        int ans = 0;
        for(int i = 0; i<h; ++i)
        {
            for(int j = 0; j<w; ++j)
            {
                if(grid[i][j] != 1)
                    continue;
                
                grid[i][j] = -1;
                int sz = 0;
                queue<pair<int, int>> q;
                q.emplace(make_pair(i, j));
                while(!q.empty())
                {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    ++sz;
                    for(int k = 0; k<4; ++k)
                    {
                        int next_x = x+dxs[k];
                        int next_y = y+dys[k];
                        if(next_x == -1 || next_x == w || next_y == -1 || next_y == h || grid[next_y][next_x] != 1)
                            continue;
                        
                        grid[next_y][next_x] = -1;
                        q.emplace(make_pair(next_y, next_x));
                    }
                }
                ans = max(ans, sz);
            }
        }

        return ans;        
    }
};
