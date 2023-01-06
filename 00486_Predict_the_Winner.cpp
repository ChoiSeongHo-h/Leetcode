"""
https://leetcode.com/problems/predict-the-winner/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    vector<vector<int>> cache;
    int get_expectation(vector<int>& nums, int l, int r)
    {
        if(r-l == 1)
            return abs(nums[l] - nums[r]);
        
        if(cache[l][r] != 2000000000)
            return cache[l][r];
      
        int l_exp = nums[l] - get_expectation(nums, l+1, r);
        int r_exp = nums[r] - get_expectation(nums, l, r-1);
        int exp = max(l_exp, r_exp);
        if(cache[l][r] == 2000000000)
            cache[l][r] = exp;
        return exp;
    }

    bool PredictTheWinner(vector<int>& nums) 
    {
        int sz = nums.size();
        if(sz == 1)
            return true;

        cache = vector<vector<int>>(sz, vector<int>(sz, 2000000000));
        int l = 0;
        int r = sz-1;
        int exp = get_expectation(nums, l, r);
        if(exp < 0)
            return false;
      
        return true;
    }
};
