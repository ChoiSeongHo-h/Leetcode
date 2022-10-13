/*
https://leetcode.com/problems/shortest-path-in-binary-matrix/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int n;
    vector<vector<int>>* grid_ptr;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;       
        
        grid_ptr = &grid;
        
        queue<pair<int, int>> q;
        q.emplace(make_pair(0, 0));
        vector<vector<bool>> emplaced(n, vector<bool>(n, false));
        emplaced[0][0] = true;
        int depth = 1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(x == n-1 && y == n-1)
                    return depth;
                
                int next_x, next_y;
                for(int i = -1; i <= 1; ++i)
                {
                    for(int j = -1; j <= 1; ++j)
                    {
                        next_x = x+i;
                        next_y = y+j;
                        if(IsOK(next_y, next_x) && !emplaced[next_y][next_x])
                        {
                            emplaced[next_y][next_x] = true;
                            q.emplace(make_pair(next_x, next_y));
                        }
                    }
                }
            }
            ++depth;            
        }
        
        return -1;
    }
    
    bool IsOK(int next_y, int next_x)
    {
        if(next_x < 0 || n <= next_x || next_y < 0 || n <= next_y || (*grid_ptr)[next_y][next_x] == 1)
            return false;
        
        return true;
    }
};
