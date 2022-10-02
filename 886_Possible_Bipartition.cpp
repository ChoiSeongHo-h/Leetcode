/*
https://leetcode.com/problems/possible-bipartition/
-> Accepted (Medium)
*/

class Solution 
{
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        vector<unordered_set<int>> connections(n);
        for(auto& dislike : dislikes)
        {
            connections[dislike[0]-1].emplace(dislike[1]-1);
            connections[dislike[1]-1].emplace(dislike[0]-1);
        }
      
        vector<int> colors(n, 0);
        for(int i = 0; i<n; i++)
        {
            if(colors[i])
                continue;
            
            int depth = 1;
            queue<int> q;
            q.emplace(i);
            vector<bool> emplaced(n, false);
            emplaced[i] = true;
            while(!q.empty())
            {
                int qSz = q.size();
                while(qSz--)
                {
                    int node = q.front();
                    q.pop();

                    if(depth%2 == 1)
                    {
                        colors[node] = 1;
                    }
                    else
                    {
                        colors[node] = 2;
                    }
                    
                    for(auto c : connections[node])
                    {
                        if(depth%2 == 1 && colors[c] == 1 || depth%2 == 0 && colors[c] == 2)
                            return false;
                        if(emplaced[c])
                            continue;
                        
                        q.emplace(c);
                        emplaced[c] = true;
                    }

                }
                ++depth;
            }
        }
        
        return true;
    }
};
