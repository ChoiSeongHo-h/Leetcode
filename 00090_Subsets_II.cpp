"""
https://leetcode.com/problems/subsets-ii/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        int sz = nums.size();
        vector<int> idcs(sz);
        vector<int> mask(sz);
        vector<vector<int>> comb_idcs;
        for(int cap = 0; cap<=sz; ++cap)
        {
            for(int i = 0; i<sz; ++i)
                idcs[i] = i;
          
            mask = vector<int>(sz, 0);
            for(int i = 0; i<cap; ++i)
                mask[i] = 1;

            do
            {
                vector<int> comb_idx;
                for(int i = 0; i<sz; ++i)
                {
                    if(mask[i] == 1)
                        comb_idx.emplace_back(idcs[i]);
                }
                comb_idcs.emplace_back(comb_idx);
            } while(prev_permutation(mask.begin(), mask.end()));
        }
      
        unordered_set<string> us;
        vector<vector<int>> ans;
        ans.emplace_back(vector<int>());
        sort(nums.begin(), nums.end());
        for(int i = 1; i<comb_idcs.size(); ++i)
        {
            vector<int> subset(comb_idcs[i].size());
            string str;
            for(int j = 0; j<comb_idcs[i].size(); ++j)
            {
                int idx = comb_idcs[i][j];
                subset[j] = nums[idx];
                str += char(nums[idx]+20);
            }

            if(us.find(str) == us.end())
            {
                us.emplace(str);
                ans.emplace_back(subset);
            }
        }
      
        return ans;
    }
};
