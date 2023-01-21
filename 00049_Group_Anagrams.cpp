"""
https://leetcode.com/problems/group-anagrams/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, int> umap;
        vector<vector<string>> ans;
        int sz = strs.size();
        for(int i = 0; i<sz; ++i)
        {
            auto str = strs[i];
            string origin(str);
            sort(str.begin(), str.end());

            if(umap.find(str) == umap.end())
            {
                umap.emplace(str, ans.size());
                ans.emplace_back(vector<string>{origin});
            }
            else
            {
                int idx = umap[str];
                ans[idx].emplace_back(origin);
            }
        }
      
        return ans;
    }
};
