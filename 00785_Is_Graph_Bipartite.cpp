"""
https://leetcode.com/problems/is-graph-bipartite/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int sz = graph.size();
        vector<int> colors(sz, -1);
        for(int i = 0; i<sz; ++i)
        {
            if(colors[i] != -1)
                continue;

            queue<int> q;
            q.emplace(i);
            vector<int> emplaced(sz, 0);
            emplaced[i] = 1;
            int depth = 0;
            while(!q.empty())
            {
                int q_sz = q.size();
                while(q_sz--)
                {
                    int node = q.front();
                    q.pop();

                    if(depth % 2 == 1)
                        colors[node] = 1;
                    else
                        colors[node] = 0;
                  
                    for(auto next : graph[node])
                    {
                        if(colors[next] == colors[node])
                            return false;
                            
                        if(emplaced[next] == 1)
                            continue;

                        q.emplace(next);
                        emplaced[next] = 1;
                    }
                }
                ++depth;
            }
        }

        return true;
    }
};
