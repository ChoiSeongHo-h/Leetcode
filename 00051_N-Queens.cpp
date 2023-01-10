"""
https://leetcode.com/problems/n-queens/
-> Accepted (Hard)
"""
  
class Solution 
{
public:
    vector<vector<string>> ans;
    vector<int> visited_x;
    vector<int> visited_lt_rb;
    vector<int> visited_rt_lb;
    void get_ans(int n, vector<string>& plane, int y)
    {
        if(y == n)
        {
            ans.emplace_back(plane);
            return;
        }

        for(int x = 0; x<n; ++x)
        {
            if(is_ok(plane, y, x, n))
            {
                plane[y][x] = 'Q';
                visited_x[x] = 1;
                int lt_rb_idx = n-1+y-x;
                int rt_lb_idx = x+y;
                visited_lt_rb[lt_rb_idx] = 1;
                visited_rt_lb[rt_lb_idx] = 1;
                get_ans(n, plane, y+1);
                plane[y][x] = '.';
                visited_x[x] = 0;
                visited_lt_rb[lt_rb_idx] = 0;
                visited_rt_lb[rt_lb_idx] = 0;
            }
        }
    }

    bool is_ok(vector<string>& plane, int y, int x, int n)
    {
        int lt_rb_idx = n-1+y-x;
        int rt_lb_idx = x+y;
        if(visited_x[x] || visited_lt_rb[lt_rb_idx] || visited_rt_lb[rt_lb_idx])
            return false;
        return true;
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        string fill;
        for(int i = 0; i<n; ++i)
            fill += ".";
        vector<string> plane(n, fill);
        visited_x = vector<int>(n, 0);
        visited_lt_rb = vector<int>(2*n-1, 0);
        visited_rt_lb = vector<int>(2*n-1, 0);
        get_ans(n, plane, 0);

        return ans;
    }
};
