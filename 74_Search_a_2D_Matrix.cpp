/*
https://leetcode.com/problems/search-a-2d-matrix/
-> Accepted (Medium)
*/

class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int h = matrix.size();
        int w = matrix[0].size();
        if(matrix[0][0] > target || matrix[h-1][w-1] < target)
            return false;

        int left = 0;
        int right = w*h;
        while(left < right)
        {
            int mid = (left+right)/2;
            int y = mid/w;
            int x = mid%w;
            if(target == matrix[y][x])
                return true;
            else if(target < matrix[y][x])
                right = mid;
            else
                left = mid+1;
        }
        
        return false;
    }
};
