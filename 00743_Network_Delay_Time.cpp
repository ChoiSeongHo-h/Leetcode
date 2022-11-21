"""
https://leetcode.com/problems/network-delay-time/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int, int>>> tb(n+1);
        for(int i = 0; i<times.size(); ++i)
        {
            tb[times[i][0]].emplace_back(make_pair(times[i][1], times[i][2]));
        }

        int time = 0;
        set<pair<int, int>> heap;
        vector<bool> visited(n+1, false);
        visited[k] = true;
        int num_visited = 1;
        for(auto& i : tb[k])
        {
            heap.emplace(make_pair(i.second+time, i.first));
        }
        if(heap.empty())
            return -1;

        while(!heap.empty())
        {
            time = heap.begin()->first;
            vector<int> nows;
            while(heap.begin()->first == time)
            {
                int now = heap.begin()->second;
                if(!visited[now])
                {
                    nows.emplace_back(now);
                    visited[now] = true;
                }
                heap.erase(heap.begin());
            }

            num_visited += nows.size();
            if(num_visited == n)
                return time;

            for(auto now : nows)
            {
                for(auto& e : tb[now])
                {
                    heap.emplace(make_pair(e.second+time, e.first));
                }
            }
        }

        return -1;
    }
};
