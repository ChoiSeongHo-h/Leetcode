/*
https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
-> Accepted (Medium)
*/

class Solution
{
public:
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        vector<bool> participated(n, false);
        vector<vector<int>> completeEdges;
        for(auto& edge : edges)
        {
            completeEdges.emplace_back(vector<int>{edge[0], edge[1]});
            completeEdges.emplace_back(vector<int>{edge[1], edge[0]});
            participated[edge[0]] = true;
            participated[edge[1]] = true;
        }
        
        vector<vector<int>> groups(n, vector<int>{});
        for(int i = 0; i<n; i++)
        {
            if(participated[i])
                continue;
            
            groups[i] = vector<int>{i};
        }
        
        for(int i = 0; i<completeEdges.size(); i++)
        {
            int from = completeEdges[i][0];
            int next = completeEdges[i][1];
            groups[from].emplace_back(next);
        }
        

        
        vector<bool> modified(n, false);
        for(int root = 0; root<n; root++)
        {
            if(!participated[root])
                continue;
            if(groups[root] == vector<int>{})
                continue;
                
            modified[root] = true;
            
            queue<int> q;
            q.emplace(root);
            vector<bool> emplaced(n, false);
            emplaced[root] = true;
            auto group = vector<int>{};
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                
                for(auto i : groups[node])
                {
                    if(emplaced[i])
                        continue;
                    
                    group.emplace_back(i);
                    emplaced[i] = true;
                    q.emplace(i);
                }
                groups[node].clear();
            }
            
            groups[root] = group;
        }
        

        
        vector<int> sums;
        int sum = 0;
        for(int i = 0; i<n; i++)
        { 
            if(participated[i] == false)
            {
                sums.emplace_back(1);
                sum += 1;
            }
            else if(modified[i] == true)
            {
                sums.emplace_back((int)groups[i].size() + 1);
                sum += (int)groups[i].size() + 1;
            }
        }
        
        long long ans = 0;
        for(int i = sums.size()-1; i>=0; --i)
        {
            sum -= sums[i];
            ans += (long long)sum*(long long)sums[i];
        }
        
        return ans;
    }
};
