/*
https://leetcode.com/problems/minimum-height-trees/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adj(n);
        for(auto& edge:edges)
        {
            adj[edge[0]].emplace_back(edge[1]);                                   
            adj[edge[1]].emplace_back(edge[0]);
        }
        
        queue<int> q;
        vector<bool> emplaced(n, false);
        q.emplace(0);
        emplaced[0] = true;
        int left = 0;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            left = node;
            for(auto e : adj[node])
            {
                if(emplaced[e])
                    continue;
                
                q.emplace(e);
                emplaced[e] = true;
            }
        }
        
        emplaced = vector<bool>(n, false);
        q.emplace(left);
        emplaced[left] = true;
        int right = 0;
        int depth = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto node = q.front();
                q.pop();

                right = node;
                for(auto e : adj[node])
                {
                    if(emplaced[e])
                        continue;

                    q.emplace(e);
                    emplaced[e] = true;
                }
            }
            ++depth;
        }

        vector<int> path;
        stack<pair<int, int>> s;
        s.emplace(make_pair(-1, left));
        emplaced = vector<bool>(n, false);
        emplaced[left] = true;
        while(!s.empty())
        {
            auto parent = s.top().first;
            auto node = s.top().second;
            s.pop();
            
            if(parent != -1)
            {
                while(path.back() != parent)
                    path.pop_back();
            }
            path.emplace_back(node);
            
            if(node == right)
                break;
            
            for(auto e : adj[node])
            {
                if(emplaced[e])
                    continue;

                s.emplace(make_pair(node, e));
                emplaced[e] = true;
            }
        }

        vector<int> ans;
        if(depth%2 == 1)
        {
            ans.emplace_back(path[depth/2]);
        }
        else
        {
            ans.emplace_back(path[depth/2]);
            ans.emplace_back(path[depth/2-1]);
        }
        
        return ans;
    }
};
