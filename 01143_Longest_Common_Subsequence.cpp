"""
https://leetcode.com/problems/longest-common-subsequence/
-> Accepted (Medium)
"""

class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> tb(m+1, vector<int>(n+1, 0));
        for(int i = 1; i<=m; ++i)
        {
            for(int j = 1; j<=n; ++j)
            {
                if(text1[i-1] == text2[j-1])
                    tb[i][j] = tb[i-1][j-1]+1;
                else
                    tb[i][j] = max(tb[i-1][j], tb[i][j-1]);
            }
        }
        return tb[m][n];
    }
};
