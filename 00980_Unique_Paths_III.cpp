"""
https://leetcode.com/problems/unique-paths-iii/
-> Accepted (Hard)
"""

class Solution 
{
public:
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        vector<int> di{-1, 0, 0, 1};
        vector<int> dj{0, -1, 1, 0};
        int h = grid.size();
        int w = grid[0].size();
        if(h == 1 && w == 1)
            return 0;

        stack<vector<int>> s;
        int num_block = 0;
        for(int i = 0; i<h; ++i)
        {
            for(int j = 0; j<w; ++j)
            {
                if(grid[i][j] != -1)
                    ++num_block;

                if(grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    s.emplace(vector<int>{-1, -1, i, j});
                }
            }
        }      
      
        vector<vector<int>> path;
        path.emplace_back(vector<int>{-1, -1});
        int ans = 0;
        int cnt = 0;
        while(!s.empty())
        {
            int before_i = s.top()[0];
            int before_j = s.top()[1];
            int now_i = s.top()[2];
            int now_j = s.top()[3];
            s.pop();

            while(path.back()[0] != before_i || path.back()[1] != before_j)
            {
                int recover_i = path.back()[0];
                int recover_j = path.back()[1];
                grid[recover_i][recover_j] = 0;
                path.pop_back();
                --cnt;
            }
            path.emplace_back(vector<int>{now_i, now_j});

            grid[now_i][now_j] = -1;
            ++cnt;

            for(int k = 0; k<4; ++k)
            {
                if
                (
                    now_i + di[k] != -1 &&
                    now_i + di[k] != h &&
                    now_j + dj[k] != -1 &&
                    now_j + dj[k] != w &&
                    grid[now_i + di[k]][now_j + dj[k]] != -1
                )
                {
                    if(grid[now_i + di[k]][now_j + dj[k]] == 2)
                    {
                        if(cnt == num_block-1)
                            ++ans;

                        continue;
                    }
                  
                    s.emplace(vector<int>{now_i, now_j, now_i + di[k], now_j + dj[k]});
                }
            }
        }
        
        return ans;
    }
};
