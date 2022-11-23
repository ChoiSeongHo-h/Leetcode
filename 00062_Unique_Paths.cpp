/*
https://leetcode.com/problems/unique-paths/
-> Accepted (Medium)
*/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> table(m, vector<int>(n));
        table[0] = vector<int>(n, 1);
        for (int i = 1; i<m; i++)
        {
            table[i][0] = 1;
            for(int j = 1; j<n; j++)
            {
                table[i][j] = table[i-1][j]+table[i][j-1];
            }
        }
        return table[m-1][n-1];
    }
};
