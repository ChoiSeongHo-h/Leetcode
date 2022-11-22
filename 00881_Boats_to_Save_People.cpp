/*
https://leetcode.com/problems/boats-to-save-people/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {  
        map<int, int> histogram;
        for(int i = 0; i<people.size(); ++i)
        {
            int w = people[i];
            if(histogram.find(w) == histogram.end())
                histogram.emplace(w, 1);
            else
                ++histogram[w];
        }

        int ans = 0;
        while(!histogram.empty())
        {
            auto target_it = prev(histogram.end());
            auto comple_it = histogram.begin();
            if(target_it == comple_it)
            {
                if(target_it->first + target_it->first > limit)
                    ans += target_it->second;
                else
                {
                    ans += target_it->second/2;
                    ans += target_it->second%2;
                }
                break;
            }

            if(comple_it->first + target_it->first > limit)
            {
                ans += target_it->second;
                histogram.erase(target_it);
            }
            else
            {
                if(comple_it->second > target_it->second)
                {
                    ans += target_it->second;
                    comple_it->second -= target_it->second;
                    histogram.erase(target_it);
                }
                else if(comple_it->second < target_it->second)
                {
                    ans += comple_it->second;
                    target_it->second -= comple_it->second;
                    histogram.erase(comple_it);
                }
                else
                {
                    ans += comple_it->second;
                    histogram.erase(comple_it);
                    histogram.erase(target_it);
                }
            }
        }

        return ans;
    }
};
