"""
https://leetcode.com/problems/valid-anagram/
-> Accepted (Easy)
"""

class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        vector<int> s_hist(26, 0);
        vector<int> t_hist(26, 0);
        int a = 'a';
        for(int i = 0; i<s.length(); ++i)
            ++s_hist[s[i]-a];
        for(int i = 0; i<t.length(); ++i)
            ++t_hist[t[i]-a];
        for(int i = 0; i<26; ++i)
        {
            if(s_hist[i] != t_hist[i])
                return false;
        }
        return true;
    }
};
