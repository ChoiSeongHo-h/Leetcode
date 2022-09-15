/*
https://leetcode.com/problems/course-schedule/
-> Accepted (Medium)
*/

class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        if(prerequisites.size() == 0)
            return true;
        
        unordered_map<int, unordered_set<int>> prereqMap;
        unordered_set<int> heads;
        for(auto& prerequisite : prerequisites)
        {
            if(prerequisite[0] == prerequisite[1])
                return false;
            
            prereqMap[prerequisite[0]].emplace(prerequisite[1]);
            auto childPrereq = heads.find(prerequisite[1]);
            if(childPrereq != heads.end())
                heads.erase(childPrereq);
                
            heads.emplace(prerequisite[0]);
        }
          
        stack<array<int, 2>> courseDepthStack;
        vector<bool> visited(numCourses, false);
        stack<int> path;
        vector<bool> done(numCourses, false);
        for(auto& head : heads)
        {
            courseDepthStack.emplace(array<int, 2>{head, 1});
        }
        
        while(!courseDepthStack.empty())
        {
            int course = courseDepthStack.top()[0];
            int depth = courseDepthStack.top()[1];
            courseDepthStack.pop();

            while(path.size() != depth-1)
            {
                visited[path.top()] = false;
                path.pop();
            }
            visited[course] = true;
            done[course] = true;
            path.emplace(course);

            for(auto& next : prereqMap[course])
            {
                if(visited[next])
                    return false;
                
                if(done[next])
                    continue;
                
                courseDepthStack.emplace(array<int, 2>{next, depth+1});
            }
        }

        return true;
    }
};
