/*
https://leetcode.com/problems/house-robber-ii/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<vector<int>> max_scores;
    int sz;
    vector<int>* nums_ptr;
    int rob(vector<int>& nums) 
    {
        sz = nums.size();
        if(sz == 1)
            return nums[0];
        else if(sz == 2)
            return max(nums[0], nums[1]);
        else if(sz == 3)
            return max(max(nums[0], nums[1]), nums[2]);
        
        max_scores = vector<vector<int>>(3, vector<int>(sz, 0));
        nums_ptr = &nums;
        
        return max(max(get_score(0, 0, 0), get_score(1, 1, 0)), get_score(2, 2, 0));
    }
    
    int get_score(int task_idx, int start_idx, int acc_score)
    {
        if(task_idx >= sz || task_idx == sz-1 && start_idx == 0)
            return acc_score;
        
        acc_score += (*nums_ptr)[task_idx];
        if(acc_score > max_scores[start_idx][task_idx])
        {
            max_scores[start_idx][task_idx] = acc_score;
            return max(get_score(task_idx+2, start_idx, acc_score), get_score(task_idx+3, start_idx, acc_score));
        }
        else return 0;
    }
};
