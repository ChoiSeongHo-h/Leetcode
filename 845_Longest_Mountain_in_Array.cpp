/*
https://leetcode.com/problems/longest-mountain-in-array/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int longestMountain(vector<int>& arr)
    {
        int ans = 0;
        int aSz = arr.size();
        vector<int> l2r(aSz, 0);
        vector<int> r2l(aSz, 0);
        for(int i = 1; i<aSz; i++)
        {
            if(arr[i-1] >= arr[i])
                continue;
            
            l2r[i] = l2r[i-1]+1;
        }
        for(int i = aSz-2; i>=0; i--)
        {
            if(arr[i] <= arr[i+1])
                continue;
            
            r2l[i] = r2l[i+1]+1;
        }
        
        for(int i = 0; i<aSz; i++)
        {
            if(l2r[i] == 0 || r2l[i] == 0)
                continue;
            
            ans = max(ans, l2r[i]+r2l[i]+1);
        }

        return ans;
    }
};
