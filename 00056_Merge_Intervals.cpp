/*
https://leetcode.com/problems/merge-intervals/
-> Accepted (Medium)
*/

// map
class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        map<int, int> mp;
        for(int i = 0; i<intervals.size(); ++i)
        {
            auto &interval = intervals[i];
            auto it = mp.find(interval[0]);
            if(it != mp.end())
                it->second = max(it->second, interval[1]);
            else
            {
                mp.emplace(interval[0], interval[1]);
                it = mp.find(interval[0]);
            }
            
            while(true)
            {
                if(it == mp.end())
                    break;

                auto it_next = next(it);
                if(it_next != mp.end() && it->second >= it_next->first)
                {
                    it->second = max(it->second, it_next->second);
                    mp.erase(it_next);
                }
                else
                    break;
            }

            while(true)
            {
                if(it == mp.begin())
                    break;
                    
                auto it_prev = prev(it);
                if(it_prev->second >= it->first)
                {
                    it_prev->second = max(it_prev->second, it->second);
                    mp.erase(it);
                    it = it_prev;
                }
                else
                    break;
            }
        }

        vector<vector<int>> ans;
        for(auto &e : mp)
            ans.emplace_back(vector<int>{e.first, e.second});

        return ans;
    }
};

// sort
class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.emplace_back(intervals[0]);
        for(int i = 1; i<intervals.size(); ++i)
        {
            auto &interval = intervals[i];
            if(ans.back()[1] >= interval[0])
                ans.back()[1] = max(ans.back()[1], interval[1]);
            else
                ans.emplace_back(interval);
        }

        return ans;
    }
};
