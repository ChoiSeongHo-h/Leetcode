/*
https://leetcode.com/problems/number-of-islands/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int ans = 0;
        for(int i = 0; i<grid.size(); ++i)
        {
            for(int j = 0; j<grid[0].size(); ++j)
            {
                if(grid[i][j] != '1')
                    continue;

                ++ans;
                queue<pair<int, int>> q;
                q.emplace(make_pair(i, j));
                while(!q.empty())
                {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    if(y != 0 && grid[y-1][x] == '1')
                    {
                        grid[y-1][x] = '2';
                        q.emplace(make_pair(y-1, x));
                    }
                    if(y != grid.size()-1 && grid[y+1][x] == '1')
                    {
                        grid[y+1][x] = '2';
                        q.emplace(make_pair(y+1, x));
                    }
                    if(x != 0 && grid[y][x-1] == '1')
                    {
                        grid[y][x-1] = '2';
                        q.emplace(make_pair(y, x-1));
                    }
                    if(x != grid[0].size()-1 && grid[y][x+1] == '1')
                    {
                        grid[y][x+1] = '2';
                        q.emplace(make_pair(y, x+1));
                    }
                }
            }
        }

        return ans;
    }
};
