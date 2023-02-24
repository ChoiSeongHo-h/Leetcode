/*
https://leetcode.com/problems/shortest-bridge/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int shortestBridge(vector<vector<int>>& grid) 
    {
        vector<int> dx{0, 0, 1, -1};
        vector<int> dy{1, -1, 0, 0};
        int h = grid.size();
        int w = grid[0].size();
        queue<pair<int, int>> q1;
      
        for(int i = 0; i<h; ++i)
        {
            for(int j = 0; j<w; ++j)
            {
                if(grid[i][j] == 0)
                    continue;
                
                queue<pair<int, int>> q0;
                q0.emplace(make_pair(i, j));
                while(!q0.empty())
                {
                    int now_i = q0.front().first;
                    int now_j = q0.front().second;
                    q0.pop();

                    grid[now_i][now_j] = 2;
                    for(int k = 0; k<4; ++k)
                    {
                        int next_i = now_i+dy[k];
                        int next_j = now_j+dx[k];
                        if(next_i == -1 ||  next_i == h || next_j == -1 || next_j == w)
                            continue;

                        if(grid[next_i][next_j] == 0)
                        {
                            q1.emplace(make_pair(next_i, next_j));
                            grid[next_i][next_j] = -1;
                        }
                        else if(grid[next_i][next_j] == 1)
                        {
                            q0.emplace(make_pair(next_i, next_j));
                            grid[next_i][next_j] = 2;
                        }
                    }
                }
                i = h;
                break;
            }
        }

        int depth = 1;
        while(!q1.empty())
        {
            int sz = q1.size();
            while(sz--)
            {
                int now_i = q1.front().first;
                int now_j = q1.front().second;
                q1.pop();

                grid[now_i][now_j] = -2;
                for(int k = 0; k<4; ++k)
                {
                    int next_i = now_i+dy[k];
                    int next_j = now_j+dx[k];
                    if(next_i == -1 ||  next_i == h || next_j == -1 || next_j == w)
                        continue;

                    if(grid[next_i][next_j] == 0)
                    {
                        q1.emplace(make_pair(next_i, next_j));
                        grid[next_i][next_j] = -1;
                    }
                    else if(grid[next_i][next_j] == 1)
                    {
                        return depth;
                    }
                }
            }
            ++depth;
        }
        
        return 0;
    }
};
