/*
https://leetcode.com/problems/permutations-ii/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do
        {
            ans.emplace_back(nums);
        }
        while(next_permutation(nums.begin(), nums.end()));
        
        return ans;
    }
};
