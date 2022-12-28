"""
https://leetcode.com/problems/minimum-window-substring/
-> Accepted (Hard)
"""

class Solution 
{
public:
    unordered_map<int, int> t_umap;
    unordered_map<int, int> s_umap;
    bool is_contained()
    {
        for(auto& t_pair : t_umap)
        {
            if(s_umap.find(t_pair.first) == s_umap.end())
                return false;
            if(s_umap[t_pair.first] < t_pair.second)
                return false;
        }
        return true;
    }
    bool can_move_left(string& s, int l)
    {
        char left_char = s[l];
        if(t_umap.find(left_char) == t_umap.end())
            return true;

        return (s_umap[left_char] > t_umap[left_char]);
    }
    bool can_get_someting(string& s, int next_r)
    {
        char next_right_char = s[next_r];
        return (t_umap.find(next_right_char) != t_umap.end());
    }

    string minWindow(string s, string t) 
    {
        for(int i = 0; i<t.length(); ++i)
            ++t_umap[t[i]];
            
        int l = 0;
        int r = -1;
        int sz = s.size();
        while(!is_contained() && r != sz-1)
        {
            ++r;
            ++s_umap[s[r]];
        }
        if(!is_contained())
            return string();

        int best_len = r-l;
        int best_l = l;
        int best_r = r;

        while(true)
        {
            if(r == sz-1 && !can_move_left(s, l))
                break;

            while(can_move_left(s, l))
            {
                char left_char = s[l];
                ++l;
                --s_umap[left_char];
            }
            if(best_len > r-l)
            {
                best_len = r-l;
                best_l = l;
                best_r = r;
            }
            while(r != sz-1 && !can_get_someting(s, r+1))
            {
                ++r;
                ++s_umap[s[r]];
            }
            if(r != sz-1)
            {
                ++r;
                ++s_umap[s[r]];
            }
        }

        string ans;
        for(int i = best_l; i<=best_r; ++i)
            ans += s[i];

        return ans;
    }
};
