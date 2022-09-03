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
        

        
        vector<bool> isRoot(n, false);
        for(int root = 0; root<n; root++)
        {
            if(!participated[root])
                continue;
            if(groups[root][0] == -1)
                continue;
                
            isRoot[root] = true;
            
            queue<int> q;
            q.emplace(root);
            vector<bool> emplaced(n, false);
            emplaced[root] = true;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                
                for(auto i : groups[node])
                {
                    if(emplaced[i])
                        continue;
                    
                    emplaced[i] = true;
                    q.emplace(i);
                    if(node != root)
                        groups[root].emplace_back(i);
                }
                groups[node][0] = -1;
            }
            
        }
        

        vector<int> sums;
        long long sum = 0;
        for(int i = 0; i<n; i++)
        { 
            if(participated[i] == false)
            {
                sums.emplace_back(1);
                sum += 1;
            }
            else if(isRoot[i] == true)
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
        
        //execption
        return ans;
    }
};
