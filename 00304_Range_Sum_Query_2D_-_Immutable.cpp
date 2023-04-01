/*
https://leetcode.com/problems/range-sum-query-2d-immutable/
-> Accepted (Medium)
*/

class NumMatrix 
{
public:
    vector<vector<int>> acc;
    NumMatrix(vector<vector<int>>& matrix) 
    {
        acc = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        acc[0][0] = matrix[0][0];
      
        for(int i = 1; i<acc.size(); ++i)
            acc[i][0] = matrix[i][0];
      
        for(int j = 1; j<acc[0].size(); ++j)
            acc[0][j] = acc[0][j-1]+matrix[0][j];
      
        for(int i = 1; i<acc.size(); ++i)
        {
            for(int j = 1; j<acc[0].size(); ++j)
                acc[i][j] = acc[i][j-1]+matrix[i][j];
        }

        for(int i = 1; i<acc.size(); ++i)
        {
            for(int j = 0; j<acc[0].size(); ++j)
                acc[i][j] += acc[i-1][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        if(row1 == 0)
        {
            if(col1 == 0)
                return acc[row2][col2];
            
            return acc[row2][col2]-acc[row2][col1-1];
        }
      
        if(col1 == 0)
            return acc[row2][col2]-acc[row1-1][col2];
      
        return acc[row2][col2]-acc[row1-1][col2]-acc[row2][col1-1]+acc[row1-1][col1-1];
    }
};
