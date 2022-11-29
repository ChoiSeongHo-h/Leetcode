/*
https://leetcode.com/problems/maximal-square/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int ans = 0;
        vector<vector<int>> tb(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i<matrix.size(); ++i)
        {
            if(matrix[i][0] == '1')
            {
                ans = 1;
                tb[i][0] = 1;
            }
        }
        for(int i = 0; i<matrix[0].size(); ++i)
        {
            if(matrix[0][i] == '1')
            {
                ans = 1;
                tb[0][i] = 1;
            }
        }

        for(int i = 1; i<matrix.size(); ++i)
        {
            for(int j = 1; j<matrix[0].size(); ++j)
            {
                if(matrix[i][j] == '0')
                    continue;
                int local_min = min(tb[i][j-1], min(tb[i-1][j], tb[i-1][j-1]));
                
                tb[i][j] += matrix[i][j]-48 + local_min;
                ans = max(ans, tb[i][j]);
            }
        }
        
        return ans*ans;
    }
};
