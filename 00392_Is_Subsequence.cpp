
"""
https://leetcode.com/problems/is-subsequence/
-> Accepted (Easy)
"""

class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        int target_idx = 0;
        int candidate_idx = 0;
        int s_sz = s.size();
        int t_sz = t.size();
        while(target_idx < s_sz && candidate_idx < t_sz)
        {
            char target = s[target_idx];
            if(candidate_idx < t_sz)
            {
                char candidate = t[candidate_idx];
                if(target == candidate)
                    ++target_idx;
                    
                ++candidate_idx;
            }
        }
        if(target_idx == s_sz)
            return true;
        return false;
    }
};
