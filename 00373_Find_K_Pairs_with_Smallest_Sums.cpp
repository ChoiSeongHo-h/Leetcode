/*
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        priority_queue<pair<int, vector<int>>> pq;
        for(int i = 0; i<nums1.size(); ++i)
        {
            for(int j = 0; j<nums2.size(); ++j)
            {
                int sum = nums1[i]+nums2[j];
                if(pq.size() < k)
                {
                    pq.emplace(make_pair(sum, vector<int>{nums1[i], nums2[j]}));
                }
                else if(pq.top().first > sum)
                {
                    pq.pop();
                    pq.emplace(make_pair(sum, vector<int>{nums1[i], nums2[j]}));
                }
                else
                    break;
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty())
        {
            ans.emplace_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
