/*
https://leetcode.com/problems/majority-element-ii/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        unordered_map<int, int> umap;
        for(auto num : nums)
        {
            auto it = umap.find(num);
            if(it == umap.end())
                umap.emplace(num, 1);
            else
                ++(it->second);
        }
      
        int target = nums.size()/3;
        vector<int> ans;
        for(auto &it : umap)
        {
            if(it.second > target)
                ans.emplace_back(it.first);
        }
      
        return ans;
    }
};

