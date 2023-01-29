"""
https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
-> Accepted (Medium)
"""

class Solution 
{
public:
    vector<vector<int>> dp_tb;
    vector<vector<int>> max_tb;
    int get_partial(vector<int>& arr, int start, int end)
    {
        if(end-start == 1)
            return 0;

        int local_min = INT_MAX;
        for(int partition = start+1; partition<end; ++partition)
        {
            int l_max = max_tb[start][partition-1];
            int r_max = max_tb[partition][end-1];
          
            int l_dp = 0;
            if(dp_tb[start][partition] == -1)
                dp_tb[start][partition] = get_partial(arr, start, partition);
            l_dp = dp_tb[start][partition];
          
            int r_dp = 0;
            if(dp_tb[partition][end] == -1)
                dp_tb[partition][end] = get_partial(arr, partition, end);
            r_dp = dp_tb[partition][end];
          
            local_min = min(local_min, l_max*r_max + l_dp + r_dp);
        }
      
        return local_min;
    }

    int mctFromLeafValues(vector<int>& arr) 
    {
        int sz = arr.size();
        dp_tb = vector<vector<int>>(sz+1, vector<int>(sz+1, -1));
        max_tb = vector<vector<int>>(sz, vector<int>(sz));
        for(int i = 0; i<sz; ++i)
        {
            max_tb[i][i] = arr[i];
            for(int j = i+1; j<sz; ++j)
                max_tb[i][j] = max(max_tb[i][j-1], arr[j]);
        }

        return get_partial(arr, 0, arr.size());
    }
};
