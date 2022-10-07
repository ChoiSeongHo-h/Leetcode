/*
https://leetcode.com/problems/01-matrix/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int h = mat.size();
        int w = mat[0].size();
        
        vector<vector<int>> ans(h, vector<int>(w, -1));
        for(int i = 0; i<h; ++i)
        {
            for(int j = 0; j<w; ++j)
            {
                if(mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    continue;
                }
            }
        }
        
        queue<pair<int, int>> q;
        for(int i = 0; i<h; ++i)
        {
            for(int j = 0; j<w; ++j)
            {
                if(i != 0 && ans[i-1][j] == 0 && ans[i][j] == -1)
                {
                    ans[i][j] = 1;
                    q.emplace(make_pair(i, j));
                }
                if(i != h-1 && ans[i+1][j] == 0 && ans[i][j] == -1)
                {
                    ans[i][j] = 1;
                    q.emplace(make_pair(i, j));
                }
                if(j != 0 && ans[i][j-1] == 0 && ans[i][j] == -1)
                {
                    ans[i][j] = 1;
                    q.emplace(make_pair(i, j));
                }
                if(j != w-1 && ans[i][j+1] == 0 && ans[i][j] == -1)
                {
                    ans[i][j] = 1;
                    q.emplace(make_pair(i, j));
                }
            }
        }
        
        int depth = 2;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                if(i != 0 && ans[i-1][j] == -1)
                {
                    ans[i-1][j] = depth;
                    q.emplace(make_pair(i-1, j));
                }
                if(i != h-1 && ans[i+1][j] == -1)
                {
                    ans[i+1][j] = depth;
                    q.emplace(make_pair(i+1, j));
                }
                if(j != 0 && ans[i][j-1] == -1)
                {
                    ans[i][j-1] = depth;
                    q.emplace(make_pair(i, j-1));
                }
                if(j != w-1 && ans[i][j+1] == -1)
                {
                    ans[i][j+1] = depth;
                    q.emplace(make_pair(i, j+1));
                }
            }
            ++depth;
        }
        
        return ans;
    }
};
