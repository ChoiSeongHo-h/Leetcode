/*
https://leetcode.com/problems/generate-parentheses/
-> Accepted (Medium)
*/

class Solution
{
public:
    void Combine(vector<unordered_set<string>>& subMaps, int targetIdx)
    {
        for(int i = 1; i < targetIdx; i++)
        {
            for(int j = i; j < targetIdx; j++)
            {
                if(i+j != targetIdx)
                    continue;
                
                for(auto ie : subMaps[i])
                {
                    for(auto je : subMaps[j])
                    {
                        subMaps[targetIdx].emplace(je+ie);
                        subMaps[targetIdx].emplace(ie+je);
                    }           
                }
            }
        }
    }
    
    void Generate(vector<unordered_set<string>>& subMaps, int targetIdx)
    {
        for(auto i : subMaps[targetIdx-1])
            subMaps[targetIdx].emplace("("+i+")");
    }
    
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        vector<unordered_set<string>> subMaps(n+1);
        subMaps[1].emplace("()");
        if(n == 1)
        {
            res.emplace_back("()");
            return res;
        }
        
        for(int i = 2; i<=n; i++)
        {
            Combine(subMaps, i);
            Generate(subMaps, i);
        }
        
        for(auto i:subMaps[n])
            res.emplace_back(i);
        return res;
    }
};
