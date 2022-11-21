/*
https://leetcode.com/problems/non-overlapping-intervals/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        map<int, vector<int>> end_to_start_map;
        for(auto& i : intervals)
        {
            end_to_start_map[i[1]-1].emplace_back(i[0]);
        }

        int start = -100000;
        int ans = 0;
        for(auto& i : end_to_start_map)
        {
            for(auto& j : i.second)
            {
                if(j > start)
                    start = i.first;
                else
                    ++ans;
            }
        }

        return ans;
    }
};
