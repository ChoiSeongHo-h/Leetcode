/*
https://leetcode.com/problems/shortest-path-with-alternating-colors/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        vector<int> ans(n, 10e4);
        ans[0] = 0;
        if(n == 1)
            return ans;
        
        vector<vector<int>> redMaps(n);
        for(auto& redEdge : redEdges)
            redMaps[redEdge[0]].emplace_back(redEdge[1]);
        vector<vector<int>> blueMaps(n);
        for(auto& blueEdge : blueEdges)
            blueMaps[blueEdge[0]].emplace_back(blueEdge[1]);
        
        queue<int> q;
        q.emplace(0);
        vector<bool> redEmplaced(n, false);
        vector<bool> blueEmplaced(n, false);
        blueEmplaced[0] = true;
        int depth = 0;
        while(!q.empty())
        {
            int nDepthwiseNodes = q.size();
            while(nDepthwiseNodes--)
            {
                int node = q.front();
                q.pop();
                
                ans[node] = min(ans[node], depth);
                
                if(depth%2 == 0)
                {
                    for(auto next : redMaps[node])
                    {
                        if(redEmplaced[next])
                            continue;

                        q.emplace(next);
                        redEmplaced[next] = true;                     
                    }
                }
                else
                {
                    for(auto next : blueMaps[node])
                    {
                        if(blueEmplaced[next])
                            continue;

                        q.emplace(next);
                        blueEmplaced[next] = true;                     
                    }
                }
            }
            ++depth;
        }
        
        q.emplace(0);
        redEmplaced = vector<bool>(n, false);
        blueEmplaced = vector<bool>(n, false);
        redEmplaced[0] = true;
        depth = 0;
        while(!q.empty())
        {
            int nDepthwiseNodes = q.size();
            while(nDepthwiseNodes--)
            {
                int node = q.front();
                q.pop();
                
                ans[node] = min(ans[node], depth);
                
                if(depth%2 == 1)
                {
                    for(auto next : redMaps[node])
                    {
                        if(redEmplaced[next])
                            continue;

                        q.emplace(next);
                        redEmplaced[next] = true;                     
                    }
                }
                else
                {
                    for(auto next : blueMaps[node])
                    {
                        if(blueEmplaced[next])
                            continue;

                        q.emplace(next);
                        blueEmplaced[next] = true;                     
                    }
                }
            }
            ++depth;
        }
        
        for(int i = 0; i<n; i++)
            if(ans[i] == 10e4)
                ans[i] = -1;
        
        return ans;
    }
};
