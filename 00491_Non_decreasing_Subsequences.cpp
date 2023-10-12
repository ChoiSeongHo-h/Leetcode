/*
https://leetcode.com/problems/non-decreasing-subsequences/
-> Accepted (Medium)
*/

class Solution 
{
public:
    void traverse(int now_idx, vector<vector<int>>& ans, int N, vector<int>& nums, vector<int>& stack, unordered_set<string>& had)
    {
        bool emplaced = false;

        int now = nums[now_idx];
        if(stack.size() != 0)
        {
            int prev = stack.back();
            if(prev <= now)
            {
                stack.emplace_back(now);
                emplaced = true;

                string key;
                for(int i = 0; i<stack.size(); ++i)
                    key += to_string(stack[i]) + '.';
              
                if(had.find(key) == had.end())
                {
                    had.emplace(key);
                    ans.emplace_back(stack);
                }
            }
        }
        else
        {
            stack.emplace_back(now);
            emplaced = true;
        }

        if(!emplaced)
            return;
            
        for(int i = now_idx+1; i<N; ++i)
            traverse(i, ans, N, nums, stack, had);

        stack.pop_back();
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        int N = nums.size();
        unordered_set<string> had;
        for(int i = 0; i<N; ++i)
        {
            vector<int> stack;
            traverse(i, ans, N, nums, stack, had);
        }

        return ans;
    }
};
