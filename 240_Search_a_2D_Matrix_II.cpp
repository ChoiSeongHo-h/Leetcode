/*
https://leetcode.com/problems/search-a-2d-matrix-ii/
-> Accepted (Medium)
*/

class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i<m; i++)
        {
            auto& vec = matrix[i];
            int left = 0;
            int right = n;
            while(left<right)
            {
                int mid = (left+right)/2;
                if(vec[mid] == target)
                    return true;
                
                if(vec[mid] < target)
                {
                    left = mid+1;
                    continue;
                }
                else
                {
                    right = mid;
                    continue;
                }
            }
        }
        
        return false;
    }
};
