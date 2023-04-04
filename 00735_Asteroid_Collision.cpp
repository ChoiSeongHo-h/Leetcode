/*
https://leetcode.com/problems/asteroid-collision/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> s;
        for(int i = 0; i<asteroids.size(); ++i)
        {
            int now = asteroids[i];
            if(now > 0)
            {
                s.emplace(now);
                continue;
            }

            bool is_break = false;
            while(!s.empty() && s.top() > 0)
            {
                if(s.top() < -now)
                    s.pop();
                else
                {
                    if(s.top() == -now)
                        s.pop();
                  
                    is_break = true;
                    break;
                }
            }
          
            if(!is_break)
                s.emplace(asteroids[i]);
        }

        vector<int> ans(s.size());
        for(int i = s.size()-1; i>=0; --i)
        {
            ans[i] = s.top();
            s.pop();
        }

        return ans;
    }
};
