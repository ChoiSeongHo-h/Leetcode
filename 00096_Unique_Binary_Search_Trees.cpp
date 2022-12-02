"""
https://leetcode.com/problems/unique-binary-search-trees/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    int numTrees(int n) 
    {
        vector<int> tb(n+1, 0);
        tb[0] = 1;
        tb[1] = 1;
        for(int ni = 2; ni<=n; ++ni)
        {
            for(int i = 1; i<=ni; ++i)
                tb[ni] += tb[max(ni-i, i-1)]*tb[min(i-1, ni-i)];
        }
        
        return tb.back();
    }
};
