"""
https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
-> Accepted (Medium)
"""

class Solution 
{
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int all = accumulate(nums.begin(), nums.end(), 0);
        if(all % k != 0)
            return false;
        int target = all / k;
        for(auto num : nums)
        {
            if(num > target)
                return false;
        }
      
        int acc = 0;
        stack<int> s;
        s.emplace(0);
        vector<bool> used(nums.size(), false);
        used[0] = true;
        while(!s.empty())
        {
            int now = s.top();

            acc += nums[now];
            if(acc == target)
            {
                --k;
                if(k == 0)
                    return true;
                acc = 0;
                for(int i = 0; i<nums.size(); ++i)
                {
                    if(used[i])
                        continue;
                    
                    s.emplace(i);
                    used[i] = true;
                    break;
                }
                continue;
            }

            int next = now+1;
            while(true)
            {
                while
                (
                    (next < nums.size()) &&
                    (nums[next] + acc > target || used[next])
                )
                    ++next;
                if(next == nums.size())
                {
                    next = now+1;
                    s.pop();
                    used[now] = false;
                    if(acc == 0)
                    {
                        acc = target;
                        ++k;
                    }
                    acc -= nums[now];
                    if(now == 0)
                        return false;
                    now = s.top();
                }
                else
                    break;
            }

            s.emplace(next);
            used[next] = true;
        }

        return false;
    }
};
