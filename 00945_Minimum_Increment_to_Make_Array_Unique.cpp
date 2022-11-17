"""
https://leetcode.com/problems/minimum-increment-to-make-array-unique/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    int minIncrementForUnique(vector<int>& nums) 
    {
        array<int, 200002> arr;
        arr.fill(0);
        deque<int> yet;
        for(auto num : nums)
        {
            if(arr[num] == 1)
            {
                yet.emplace_back(num);
                continue;
            }
            arr[num] = 1;
        }
        if(yet.size() == 0)
            return 0;

        sort(yet.begin(), yet.end());
        deque<int> remains;
        for(int i = 0; i<arr.size(); ++i)
        {
            if(arr[i] == 1)
                continue;
            remains.emplace_back(i);
        }

        int ans = 0;
        while(!yet.empty())
        {
            int target = yet[0];
            yet.pop_front();
            while(remains[0] < target)
                remains.pop_front();
            ans += int(remains[0])-target;
            remains.pop_front();
        }

        return ans;
    }
};
