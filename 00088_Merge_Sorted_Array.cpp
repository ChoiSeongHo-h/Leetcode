/*
https://leetcode.com/problems/merge-sorted-array/
-> Accepted (Easy)
*/

class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        if(n == 0)
            return;

        if(m == 0)
        {
            nums1 = nums2;
            return;
        }

        vector<int> temp;
        for(int i = 0; i<m; ++i)
            temp.emplace_back(nums1[i]);
      
        int pt1 = 0;
        int pt2 = 0;
        int idx = 0;
        while(idx < m+n)
        {
            if(pt1 == temp.size())
            {
                nums1[idx] = nums2[pt2];
                ++pt2;
            }
            else if(pt2 == nums2.size())
            {
                nums1[idx] = temp[pt1];
                ++pt1;
            }
            else if(temp[pt1] >= nums2[pt2])
            {
                nums1[idx] = nums2[pt2];
                ++pt2;
            }
            else
            {
                nums1[idx] = temp[pt1];
                ++pt1;
            }
            ++idx;
        }
    }
};
