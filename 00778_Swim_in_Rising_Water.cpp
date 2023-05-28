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

// binary search
class Solution 
{
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        vector<int> dx{-1, 0, 0, 1};
        vector<int> dy{0, -1, 1, 0};
        int n = grid.size();
      
        int l = 0;
        int r = n*n;
        while(l<r)
        {
            int mid = (l+r)/2;
            vector<vector<int>> grid_new(n, vector<int>(n));
            for(int i = 0; i<n; ++i)
            {
                for(int j = 0; j<n; ++j)
                {
                    grid_new[i][j] = grid[i][j]-mid+1;
                    grid_new[i][j] = max(grid_new[i][j], 1);
                }
            }

            stack<vector<int>> s;
            s.emplace(vector<int>{0, 0});
            grid_new[0][0] *= -1;
            int success = 0;
            while(!s.empty())
            {
                int y = s.top()[0];
                int x = s.top()[1];
                int val = grid_new[y][x];
                s.pop();

                if(y == n-1 && x == n-1)
                {
                    success = 1;
                    break;
                }

                for(int i = 0; i<4; ++i)
                {
                    int y_new = y+dy[i];
                    int x_new = x+dx[i];
                    if(y_new == -1 || y_new == n || x_new == -1 || x_new == n || grid_new[y_new][x_new] < 0 || grid_new[y_new][x_new] != -val)
                        continue;
                    
                    s.emplace(vector<int>{y_new, x_new});
                    grid_new[y_new][x_new] *= -1;
                }
            }

            if(success)
                r = mid;
            else
                l = mid+1;
        }
        
        return l;
    }
};
