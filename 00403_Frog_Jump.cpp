/*
https://leetcode.com/problems/frog-jump/
-> Accepted (Hard)
*/

class Solution 
{
public:
    vector<vector<int>> dp;

    bool traverse(unordered_map<int, int> &umap, vector<int>& stones, int before, int now)
    {
        auto it_now = umap.find(stones[now]);
        if(it_now->second == stones.size()-1)
            return true;

        if(dp[before][now] != -1)
           return bool(dp[before][now]);

        int step0 = stones[now]-stones[before]-1;
        int step1 = step0+1;
        int step2 = step1+1;
        auto it0 = umap.find(stones[now]+step0);
        auto it1 = umap.find(stones[now]+step1);
        auto it2 = umap.find(stones[now]+step2);
        bool can_go_next = false;
        if(step0 > 0 && it0 != umap.end())
            can_go_next += traverse(umap, stones, now, it0->second);
        if(step1 > 0 && it1 != umap.end())
            can_go_next += traverse(umap, stones, now, it1->second);
        if(step2 > 0 && it2 != umap.end())
            can_go_next += traverse(umap, stones, now, it2->second);
        
        dp[before][now] = can_go_next;
        return can_go_next;
    }

    bool canCross(vector<int>& stones) 
    {
        unordered_map<int, int> umap;
        for(int i = 0; i<stones.size(); ++i)
            umap.emplace(stones[i], i);
        if(stones[1] - stones[0] != 1)
            return false;
        dp = vector<vector<int>>(stones.size(), vector<int>(stones.size(), -1));
        bool can_go_next = traverse(umap, stones, 0, 1);
        
        return can_go_next;
    }
};
