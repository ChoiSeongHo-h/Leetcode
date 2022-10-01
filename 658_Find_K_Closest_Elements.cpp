/*
https://leetcode.com/problems/find-k-closest-elements/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int left = 0;
        int right = arr.size()-1;
        int mid = (left+right+1)/2;
        int min_idx = mid;
        while(left < right)
        {
            if(arr[mid] == x)
                break;
            
            if(x-arr[mid] > 0)
                left = mid+1;
            if(x-arr[mid] < 0)
                right = mid-1;
            
            mid = (left+right+1)/2;
            //printf("test : %d %d\n", mid, arr[mid]);
            if(min_idx < mid && abs(arr[min_idx] - x) > abs(arr[mid] - x))
                min_idx = mid;
            else if(min_idx > mid && abs(arr[min_idx] - x) >= abs(arr[mid] - x))
                min_idx = mid;
        }
        
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
