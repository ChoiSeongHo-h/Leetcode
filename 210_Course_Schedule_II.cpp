/*
https://leetcode.com/problems/course-schedule-ii/
-> Accepted (Medium)
*/

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<unordered_set<int>> preqs(numCourses);
        vector<vector<int>> parents(numCourses);
        vector<int> ans;
        for(auto& prerequisite : prerequisites)
        {            
            preqs[prerequisite[0]].emplace(prerequisite[1]);
            parents[prerequisite[1]].emplace_back(prerequisite[0]);
        }
        
        unordered_set<int> candidates;
        vector<int> addings;
        for(int i = 0; i<numCourses; i++)
        {
            if(!preqs[i].empty())
                continue;
            
            //printf("adding %d\n", i);
            addings.emplace_back(i);
            for(auto j : parents[i])
                candidates.emplace(j);
        }
      
        for(auto i : addings)
        {
            ans.emplace_back(i);
            for(int j = 0; j<numCourses; j++)
            {
                auto find_res = preqs[j].find(i);
                if(find_res == preqs[j].end())
                    continue;
                
                preqs[j].erase(find_res);
            }
        }
        addings.clear();
        
        int cnt = 0;
        while(!candidates.empty())
        {
            ++cnt;
            for(auto i : candidates)
            {
                if(!preqs[i].empty())
                    continue;

                addings.emplace_back(i);
                for(auto j : parents[i])
                    candidates.emplace(j);
            }
            for(auto i : addings)
            {
                auto find_res = candidates.find(i);
                if(find_res == candidates.end())
                    continue;
                candidates.erase(find_res);
                
                ans.emplace_back(i);
                for(int j = 0; j<numCourses; j++)
                {
                    auto find_res = preqs[j].find(i);
                    if(find_res == preqs[j].end())
                        continue;

                    preqs[j].erase(find_res);
                }
            }
            addings.clear();
            if(cnt>numCourses)
                return vector<int>();
        }
        if(ans.size() != numCourses)
            return vector<int>();
        
        return ans;
    }
};
