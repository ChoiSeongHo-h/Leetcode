/*
https://leetcode.com/problems/remove-invalid-parentheses/
-> Accepted (Hard)
*/

class Solution 
{
public:
    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> ans;
        queue<string> q;
        unordered_set<string> emplaced;
        q.emplace(s);
        emplaced.emplace(s);
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto node = q.front();
                q.pop();

                if(node == "")
                    return vector<string> {""};

                vector<int> hist(node.length(), 0);
                if(node[0] == '(')
                    hist[0] = 1;
                else if(node[0] == ')')
                    hist[0] = -1;

                for(int i = 1; i<node.length(); ++i)
                {
                    if(node[i] == '(')
                        hist[i] = hist[i-1] + 1;
                    else if(node[i] == ')')
                        hist[i] = hist[i-1] - 1;
                    else
                        hist[i] = hist[i-1];
                }

                int first_neg = 100000;
                int last_zero = -1;
                vector<int> rights;
                vector<int> lefts;
                for(int i = 0; i<hist.size(); ++i)
                {
                    if(node[i] == ')')
                        rights.emplace_back(i);
                    if(node[i] == '(')
                        lefts.emplace_back(i);
                    if(hist[i] < 0)
                        first_neg = min(first_neg, i);
                    if(hist[i] == 0)
                        last_zero = max(last_zero, i);
                }

                if(first_neg == 100000 && hist.back() == 0)
                {
                    ans.emplace_back(node);
                    continue;                    
                }

                if(first_neg != 100000)
                {
                    for(int i = 0; i<rights.size(); ++i)
                    {
                        if(first_neg < rights[i])
                            break;
                      
                        string next = string(node);
                        next.erase(rights[i], 1);
                        if(emplaced.find(next) == emplaced.end())
                        {
                            q.emplace(next);
                            emplaced.emplace(next);   
                        }
                    }
                }
                else
                {
                    for(int i = 0; i<lefts.size(); ++i)
                    {
                        if(lefts[i] <= last_zero)
                            continue;
                            
                        string next = string(node);
                        next.erase(lefts[i], 1);
                        if(emplaced.find(next) == emplaced.end())
                        {
                            q.emplace(next);
                            emplaced.emplace(next);   
                        }
                    }
                }
            }

            if(!ans.empty())
                break;
        }
        
        return ans;
    }
};
