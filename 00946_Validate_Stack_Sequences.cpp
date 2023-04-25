/*
https://leetcode.com/problems/validate-stack-sequences/
-> Accepted (Medium)
*/

class Solution 
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int> s;
        int j = 0;
      
        for(int i = 0; i<popped.size(); ++i)
        {
            if(!s.empty() && s.top() == popped[i])
            {
                s.pop();
                continue;
            }

            for(; j<pushed.size(); ++j)
            {
                if(popped[i] != pushed[j])
                    s.emplace(pushed[j]);
                else
                {
                    s.emplace(pushed[j]);
                    ++j;
                    --i;
                    break;
                }
            }
        }

        if(!s.empty())
            return false;
        
        return true;
    }
};
