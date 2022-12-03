"""
https://leetcode.com/problems/delete-and-earn/
-> Accepted (Medium)
"""

class Solution 
{
public:
    int deleteAndEarn(vector<int>& nums)
    {
        int max_num = -1;
        vector<int> accs(10e4+1, 0);
        for(auto num : nums)
        {
            accs[num] += num;
            max_num = max(max_num, num);
        }
        if(max_num == 1)
            return accs[1];
        
        vector<int> tb(max_num+1, 0);
        tb[1] = accs[1];
        tb[2] = max(accs[1], accs[2]);
        for(int i = 3; i<=max_num; ++i)
            tb[i] = max(tb[i-2]+accs[i], tb[i-1]);

        return tb.back();
    }
};
