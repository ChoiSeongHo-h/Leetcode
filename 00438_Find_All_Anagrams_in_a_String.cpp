"""
https://leetcode.com/problems/find-all-anagrams-in-a-string/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int s_sz = s.size();
        int p_sz = p.size();
        if(s_sz < p_sz)
            return {};

        vector<int> p_hist(26, 0);
        int a = 'a';
        for(int i = 0; i<p_sz; ++i)
            ++p_hist[p[i]-a];
      
        vector<vector<int>> s_hist(s_sz-p_sz+1, vector<int>(26, 0));
        for(int i = 0; i<p_sz; ++i)
            ++s_hist[0][s[i]-a];
      
        int s_hist_sz = s_hist.size();
        for(int start_idx = 1; start_idx<s_hist_sz; ++start_idx)
        {
            s_hist[start_idx] = vector<int>(s_hist[start_idx-1]);
            int remove_target = s[start_idx-1];
            --s_hist[start_idx][remove_target-a];
            int add_target = s[start_idx+p_sz-1];
            ++s_hist[start_idx][add_target-a];
        }
      
        vector<int> ans;
        for(int start_idx = 0; start_idx<s_hist_sz; ++start_idx)
        {
            bool pass_all = true;
            for(int i = 0; i<26; ++i)
                pass_all = pass_all*(p_hist[i] == s_hist[start_idx][i]);
            if(pass_all)
                ans.emplace_back(start_idx);
        }
        
        return ans;
    }
};
