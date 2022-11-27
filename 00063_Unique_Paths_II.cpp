/*
https://leetcode.com/problems/unique-paths-ii/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1)
            return 0;
        
        for(int i = 0; i<m; ++i)
        {
            if(obstacleGrid[i][0] == 1)
                break;

            obstacleGrid[i][0] = -1;
        }

        for(int i = 0; i<n; ++i)
        {
            if(obstacleGrid[0][i] == 1)
                break;

            obstacleGrid[0][i] = -1;
        }

        for(int i = 1; i<m; ++i)
        {
            for(int j = 1; j<n; ++j)
            {
                if(obstacleGrid[i][j] == 1)
                    continue;
                else if(obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] == 1)
                    continue;
                else if(obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] != 1)
                    obstacleGrid[i][j] = obstacleGrid[i][j-1];
                else if(obstacleGrid[i-1][j] != 1 && obstacleGrid[i][j-1] == 1)
                    obstacleGrid[i][j] = obstacleGrid[i-1][j];
                else
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }

        return -obstacleGrid[m-1][n-1];
    }
};
