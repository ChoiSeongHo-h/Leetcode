"""
https://leetcode.com/problems/longest-palindromic-substring/
-> Accepted (Medium)
"""

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int sz = s.size();
        if(sz == 1)
            return s;
        
        int same = -1;
        vector<int> left;
        vector<int> right;
        vector<int> len;
        int best_left = -1;
        int best_right = -1;
        int best_len = -1;

        for(int i = 1; i<sz; ++i)
        {
            if(same == -1)
            {
                if(s[i-1] == s[i])
                    same = i-1;
                
                continue;
            }
                
            if(s[same] == s[i])
                continue;
            
            left.emplace_back(same);
            right.emplace_back(i-1);
            int l = i-1 - same + 1;
            len.emplace_back(l);
            if(l > best_len)
            {
                best_left = same;
                best_right = i-1;
                best_len = l;
            }
            same = -1;
        }
        if(same != -1 && s[same] == s[sz-1])
        {
            left.emplace_back(same);
            right.emplace_back(sz-1);
            int l = sz-1 - same + 1;
            len.emplace_back(l);
            if(l > best_len)
            {
                best_left = same;
                best_right = sz-1;
                best_len = l;
            }
        }
        
        for(int i = 1; i<sz-1; ++i)
        {
            if(s[i-1] == s[i+1] && s[i-1] != s[i])
            {
                left.emplace_back(i-1);
                right.emplace_back(i+1);
                len.emplace_back(3);
                if(3 > best_len)
                {
                    best_left = i-1;
                    best_right = i+1;
                    best_len = 3;
                }
            }
        }

        int ssz = left.size();
        if(ssz == 0)
            return s.substr(0, 1);
            
        while(true)
        {
            int fail_cnt = 0;
            for(int i = 0; i<ssz; ++i)
            {
                if(0 < left[i] && right[i] < sz-1 && s[left[i]-1] == s[right[i]+1])
                {
                    left[i] = left[i]-1;
                    right[i] = right[i]+1;
                    int l = right[i]-left[i]+1;
                    len[i] = l;
                    if(l > best_len)
                    {
                        best_left = left[i];
                        best_right = right[i];
                        best_len = l;
                    }
                    continue;
                }

                left[i] = -1;
                ++fail_cnt;
            }
            if(fail_cnt == ssz)
                break;
        }
        
        return s.substr(best_left, best_len);
    }
};
