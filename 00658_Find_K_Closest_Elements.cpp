/*
https://leetcode.com/problems/find-k-closest-elements/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int min_idx = -1;
        if(it == arr.end())
            min_idx = arr.size()-1;
        else if(x < arr.front())
            min_idx = 0;
        else if(x == *it)
            min_idx = distance(arr.begin(), it);
        else if(abs(x-*prev(it)) <= abs(x-*it))
            min_idx = distance(arr.begin(), prev(it));
        else
            min_idx = distance(arr.begin(), it);
        
        deque<int> deq;
        int l_idx = min_idx-1;
        int r_idx = min_idx+1;
        deq.emplace_back(arr[min_idx]);
        for(int i = 1; i<k; i++)
        {
            if(l_idx == -1)
            {
                deq.emplace_back(arr[r_idx]);
                ++r_idx;
                continue;
            }
            if(r_idx == arr.size())
            {
                deq.emplace_front(arr[l_idx]);
                --l_idx;
                continue;
            }
            
            if(abs(arr[l_idx] - x) <= abs(arr[r_idx] - x))
            {
                deq.emplace_front(arr[l_idx]);
                --l_idx;
            }
            else
            {
                deq.emplace_back(arr[r_idx]);
                ++r_idx;
            }
        }
        
        vector<int> ans;
        for(auto i : deq)
            ans.emplace_back(i);

        return ans;
    }
};
