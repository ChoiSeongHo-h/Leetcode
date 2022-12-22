"""
https://leetcode.com/problems/delete-operation-for-two-strings/
-> Accepted (Medium)
"""

class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        int l1 = word1.length();
        int l2 = word2.length();
        vector<vector<int>> tb(l1+1, vector<int>(l2+1, 0));
        for(int i = 1; i<=l1; ++i)
        {
            for(int j = 1; j<=l2; ++j)
            {
                if(word1[i-1] == word2[j-1])
                    tb[i][j] = tb[i-1][j-1]+1;
                else
                    tb[i][j] = max(tb[i-1][j], tb[i][j-1]);
            }
        }

        return l1-tb[l1][l2] + l2-tb[l1][l2];
    }
};
