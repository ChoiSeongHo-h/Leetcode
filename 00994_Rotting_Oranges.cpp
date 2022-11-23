/*
https://leetcode.com/problems/rotting-oranges/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        set<pair<int, int>> freshs;
        set<pair<int, int>> rottens;
        for(int i = 0; i<m; ++i)
        {
            for(int j = 0; j<n; ++j)
            {
                if(grid[i][j] == 0)
                    continue;
                
                if(grid[i][j] == 1)
                    freshs.emplace(make_pair(i, j));
                else
                    rottens.emplace(make_pair(i, j));
            }
        }

        if(freshs.empty())
            return 0;
        if(rottens.empty())
            return -1;

        int t = 0;
        while(!rottens.empty())
        {
            queue<pair<int, int>> q;
            for(auto& rotten : rottens)
               q.emplace(rotten);
            set<pair<int, int>> candidates;
            while(!q.empty())
            {
                int q_sz = q.size();
                while(q_sz--)
                {
                    int x = q.front().second;
                    int y = q.front().first;
                    q.pop();

                    if(x != 0 && grid[y][x-1] == 1)
                        candidates.emplace(make_pair(y, x-1));
                    if(y != 0 && grid[y-1][x] == 1)
                        candidates.emplace(make_pair(y-1, x));
                    if(x != n-1 && grid[y][x+1] == 1)
                        candidates.emplace(make_pair(y, x+1));
                    if(y != m-1 && grid[y+1][x] == 1)
                        candidates.emplace(make_pair(y+1, x));
                }
                if(!candidates.empty())
                    ++t;
                for(auto& candidate : candidates)
                {
                    grid[candidate.first][candidate.second] = 2;
                    rottens.emplace(candidate);
                    freshs.erase(freshs.find(candidate));
                }
                vector<pair<int, int>> del_list;
                for(auto& rotten : rottens)
                {
                    int x = rotten.second;
                    int y = rotten.first;
                    if
                    (
                        (x == 0 || x != 0 && (grid[y][x-1] == 2 || grid[y][x-1] == 0)) &&
                        (y == 0 || y != 0 && (grid[y-1][x] == 2 || grid[y-1][x] == 0)) &&
                        (x == n-1 || x != n-1 && (grid[y][x+1] == 2 || grid[y][x+1] == 0)) &&
                        (y == m-1 || y != m-1 && (grid[y+1][x] == 2 || grid[y+1][x] == 0))
                    )
                        del_list.emplace_back(rotten);
                }
                for(auto& del_element : del_list)
                    rottens.erase(rottens.find(del_element));
            }
        }

        if(freshs.empty())
            return t;
        return -1;
    }
};
