"""
https://leetcode.com/problems/integer-break/
-> Accepted (Medium)
"""

class Solution 
{
public:
    int integerBreak(int n) 
    {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;

        vector<int> tb(n+1, 0);
        tb[2] = 2;
        tb[3] = 3;
        for(int i = 4; i<=n; ++i)
            tb[i] = max(tb[i-2]*2, tb[i-3]*3);

        return tb[n];
    }
};


