/*
https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
-> Accepted (Medium)
*/

class Solution 
{
public:
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> graph(n);
        for(int i = 0; i<edges.size(); ++i)
        {
            graph[edges[i][0]].emplace_back(edges[i][1]);
            graph[edges[i][1]].emplace_back(edges[i][0]);
        }
        
        vector<int> group_nums;
        vector<int> used(n, 0);
        for(int i = 0; i<n; ++i)
        {
            if(graph[i].size() == 0)
            {
                group_nums.emplace_back(1);
                continue;
            }
            if(used[i])
                continue;

            queue<int> q;
            q.emplace(i);
            unordered_set<int> emplaced;
            emplaced.emplace(i);
            int local_num = 0;
            while(!q.empty())
            {
                int now = q.front();
                q.pop();

                ++local_num;
                used[now] = true;
                for(auto next : graph[now])
                {
                    if(emplaced.find(next) != emplaced.end())
                        continue;
                    q.emplace(next);
                    emplaced.emplace(next);
                }
            }
            group_nums.emplace_back(local_num);
        }
        
        long long ans = 0;
        long long acc = accumulate(group_nums.begin(), group_nums.end(), 0);
        for(int i = 0; i<group_nums.size()-1; ++i)
        {
            acc -= group_nums[i];
            ans += group_nums[i]*acc;
        }
        return ans;
    }
};
