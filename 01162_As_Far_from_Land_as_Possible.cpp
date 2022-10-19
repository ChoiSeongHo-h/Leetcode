/*
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        if(grid.size() == 1 && grid[0].size() == 1)
            return -1;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        int nLand = 0;
        int nWater = 0;
        vector<set<pair<int, int>>> landBDs(1);
        int bdIdx = 0;
        set<pair<int, int>> emplaced;
        for(int i = 0; i<rows; ++i)
        {
            for(int j = 0; j<cols; ++j)
            {
                if(grid[i][j] == 0)
                {
                    ++nWater;
                    continue;                    
                }
                
                ++nLand;
                if(emplaced.find(make_pair(i, j)) != emplaced.end())
                    continue;
                
                landBDs.resize(bdIdx+1);
                queue<pair<int, int>> ijLand;
                ijLand.emplace(make_pair(i, j));
                while(!ijLand.empty())
                {
                    int iLand = ijLand.front().first;
                    int jLand = ijLand.front().second;
                    ijLand.pop();
                    

                    if(iLand-1 != -1)
                    {
                        if (grid[iLand-1][jLand] == 0)
                        {
                          landBDs[bdIdx].emplace(make_pair(iLand, jLand));
                        }
                        else if(grid[iLand-1][jLand] == 1 &&
                            emplaced.find(make_pair(iLand-1, jLand)) == emplaced.end())
                        {
                            ijLand.emplace(make_pair(iLand-1, jLand));
                            emplaced.emplace(make_pair(iLand-1, jLand));
                        }
                    }
                    if(iLand+1 != cols)
                    {
                        if (grid[iLand+1][jLand] == 0)
                        {
                            landBDs[bdIdx].emplace(make_pair(iLand, jLand));
                        }
                        else if(grid[iLand+1][jLand] == 1 &&
                            emplaced.find(make_pair(iLand+1, jLand)) == emplaced.end())
                        {
                            ijLand.emplace(make_pair(iLand+1, jLand));
                            emplaced.emplace(make_pair(iLand+1, jLand));
                        }
                    }
                    if(jLand-1 != -1)
                    {
                        if (grid[iLand][jLand-1] == 0)
                        {
                            landBDs[bdIdx].emplace(make_pair(iLand, jLand));
                        }
                        else if(grid[iLand][jLand-1] == 1 &&
                            emplaced.find(make_pair(iLand, jLand-1)) == emplaced.end())
                        {
                            ijLand.emplace(make_pair(iLand, jLand-1));
                            emplaced.emplace(make_pair(iLand, jLand-1));
                        }
                    }
                    if(jLand+1 != rows)
                    {
                        if(grid[iLand][jLand+1] == 0)
                        {
                            landBDs[bdIdx].emplace(make_pair(iLand, jLand));
                        }
                        else if(grid[iLand][jLand+1] == 1 &&
                            emplaced.find(make_pair(iLand, jLand+1)) == emplaced.end())
                        {
                            ijLand.emplace(make_pair(iLand, jLand+1));
                            emplaced.emplace(make_pair(iLand, jLand+1));
                        }
                    }

                }
                ++bdIdx;
            }
        }
        
        if(nLand == 0 || nWater == 0)
            return -1;
      
        vector<vector<int>> distMap(rows, vector<int>(cols, rows+cols+1));
        for(auto landBDSet : landBDs)
        {
            queue<pair<int, int>> distQ;
            set<pair<int, int>> distEmplaced;
            
            for(auto ijPair : landBDSet)
            {
                distQ.emplace(ijPair);  
                distEmplaced.emplace(ijPair);                
            }
            int depth = 0;
            while(!distQ.empty())
            {
                int depthwiseNodes = distQ.size();
                while(depthwiseNodes--)
                {
                    int iDist = distQ.front().first;
                    int jDist = distQ.front().second;
                    distQ.pop();

                    //printf("dist : %d, %d : %d %d\n", iDist, jDist, distMap[iDist][jDist], depth);
                    distMap[iDist][jDist] = min(distMap[iDist][jDist], depth);
                    
                    pair<int, int> nextPair;
                    nextPair = make_pair(iDist-1, jDist);
                    if(nextPair.first != -1 &&
                        grid[nextPair.first][nextPair.second] != 1 &&
                        distEmplaced.find(nextPair) == distEmplaced.end())
                    {
                        distQ.emplace(nextPair);  
                        distEmplaced.emplace(nextPair);     
                    }
                    nextPair = make_pair(iDist+1, jDist);
                    if(nextPair.first != cols &&
                        grid[nextPair.first][nextPair.second] != 1 &&
                        distEmplaced.find(nextPair) == distEmplaced.end())
                    {
                        distQ.emplace(nextPair);  
                        distEmplaced.emplace(nextPair);     
                    }
                    nextPair = make_pair(iDist, jDist-1);
                    if(nextPair.second != -1 &&
                        grid[nextPair.first][nextPair.second] != 1 &&
                        distEmplaced.find(nextPair) == distEmplaced.end())
                    {
                        distQ.emplace(nextPair);  
                        distEmplaced.emplace(nextPair);     
                    }
                    nextPair = make_pair(iDist, jDist+1);
                    if(nextPair.second != rows &&
                        grid[nextPair.first][nextPair.second] != 1 &&
                        distEmplaced.find(nextPair) == distEmplaced.end())
                    {
                        distQ.emplace(nextPair);  
                        distEmplaced.emplace(nextPair);     
                    }
                }
                ++depth;
                

            }
        }
      
        int maxDist = 0;
        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                if(grid[i][j] == 1)
                    continue;
                
                maxDist = max(maxDist, distMap[i][j]);
                
            }
        }
        

        return maxDist;
        
    }
};
