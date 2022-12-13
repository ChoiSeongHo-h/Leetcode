"""
https://leetcode.com/problems/pacific-atlantic-water-flow/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int h = heights.size();
        int w = heights[0].size();

        vector<vector<int>> can_pacific(h, vector<int>(w, -1));
        vector<vector<int>> can_atlantic(h, vector<int>(w, -1));
        queue<array<int, 2>> q;
        for(int i = 0; i<w; ++i)
            q.emplace(array<int, 2>{0, i});
        for(int i = 0; i<h; ++i)
            q.emplace(array<int, 2>{i, 0});
        while(!q.empty())
        {
            int x = q.front()[1];
            int y = q.front()[0];
            q.pop();

            can_pacific[y][x] = 1;
            for(int i = 0; i<4; ++i)
            {
                int next_x = x+dx[i];
                int next_y = y+dy[i];
                if(next_x != -1 && next_x != w && next_y != -1 && next_y != h)
                {
                    if(can_pacific[next_y][next_x] == -1 && heights[next_y][next_x] >= heights[y][x])
                    {
                        q.emplace(array<int, 2>{next_y, next_x});
                        can_pacific[next_y][next_x] = 0;
                    }
                }
            }
        }
    
        vector<vector<int>> ans;
        for(int i = 0; i<w; ++i)
            q.emplace(array<int, 2>{h-1, i});
        for(int i = 0; i<h; ++i)
            q.emplace(array<int, 2>{i, w-1});
        while(!q.empty())
        {
            int x = q.front()[1];
            int y = q.front()[0];
            q.pop();
            
            if(can_atlantic[y][x] == 1)
                continue;
            can_atlantic[y][x] = 1;
            if(can_pacific[y][x] == 1)
                ans.emplace_back(vector<int>{y, x});
            for(int i = 0; i<4; ++i)
            {
                int next_x = x+dx[i];
                int next_y = y+dy[i];
                if(next_x != -1 && next_x != w && next_y != -1 && next_y != h)
                {
                    if(can_atlantic[next_y][next_x] == -1 && heights[next_y][next_x] >= heights[y][x])
                    {
                        q.emplace(array<int, 2>{next_y, next_x});
                        can_atlantic[next_y][next_x] = 0;
                    }
                }
            }
        }

        return ans;
    }
};
