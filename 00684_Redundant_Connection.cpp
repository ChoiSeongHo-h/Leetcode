"""
https://leetcode.com/problems/redundant-connection/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int sz = edges.size();
        vector<vector<int>> g(sz+1);
        int w[1001][1001] = {-1, };
        for(int i = 0; i<sz; ++i)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            g[from].emplace_back(to);
            g[to].emplace_back(from);
            w[from][to] = i;
            w[to][from] = i;
        }

        stack<pair<int, int>> s;
        s.emplace(make_pair(-1, edges[0][0]));
        vector<int> visited(sz+1, 0);
        vector<int> path;
        path.emplace_back(-1);
        int is_in_path[1001] = {0, };
        int loop_start = -1;
        while(!s.empty())
        {
            auto e = s.top();
            s.pop();

            int parent = e.first;
            int now = e.second;
            if(is_in_path[now] == 1)
            {
                loop_start = now;
                while(path.back() != -1 && path.back() != parent)
                {
                    is_in_path[path.back()] = 0;
                    path.pop_back();
                }
                break;
            }
            if(visited[now] == 1)
                continue;

            visited[now] = 1;
            while(path.back() != -1 && path.back() != parent)
            {
                is_in_path[path.back()] = 0;
                path.pop_back();
            }
            is_in_path[now] = 1;
            path.emplace_back(now);

            for(int i = 0; i<g[now].size(); ++i)
            {
                if(g[now][i] == parent)
                    continue;

                s.emplace(make_pair(now, g[now][i]));
            }
        }

        int ans_idx = -1;
        for(int i = path.size()-1; i>=2; --i)
        {
            int e0 = path[i-1];
            int e1 = path[i];
            ans_idx = max(ans_idx, w[e0][e1]);
            ans_idx = max(ans_idx, w[e1][e0]);
            if(e0 == loop_start)
                break;
        }
        ans_idx = max(ans_idx, w[loop_start][path.back()]);
        ans_idx = max(ans_idx, w[path.back()][loop_start]);
      
        return edges[ans_idx];
    }
};
