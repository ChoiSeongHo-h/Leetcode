/*
https://leetcode.com/problems/partition-labels/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<int> partitionLabels(string s) 
    {
        int a = 'a';
        int sz = s.size();
        vector<int> hist_r(26, 0);
        for(int i = 0; i<sz; ++i)
            ++hist_r[s[i]-a];

        vector<int> ans;
        int acc = 0;
        vector<int> hist_l(26, 0);
        for(int i = 0; i<sz; ++i)
        {
            ++hist_l[s[i]-a];
            --hist_r[s[i]-a];

            bool can_partition = true;
            for(int j = 0; j<26; ++j)
                can_partition *= (hist_l[j] * hist_r[j] == 0);

            if(can_partition)
            {
                ans.emplace_back(i+1 - acc);
                acc += ans.back();
                hist_l = vector<int>(26, 0);
            }
        }
        
        return ans;
    }
};
