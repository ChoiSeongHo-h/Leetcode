"""
https://leetcode.com/problems/largest-number/
-> Accepted (Medium)
"""
  
bool cmp(string& s1, string& s2)
{
    return s1+s2>s2+s1;
}

class Solution 
{
public:
    string largestNumber(vector<int> &num) 
    {
        vector<string> strs;
        for(auto i : num)
            strs.emplace_back(to_string(i));

        sort(strs.begin(), strs.end(), cmp);
        string ans;
        for(auto& str : strs)
            ans += str;

        while(ans[0] == '0' && ans.length() > 1)
            ans.erase(0, 1);
            
        return ans;
    }
};
