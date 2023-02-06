"""
https://leetcode.com/problems/longest-string-chain/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    vector<vector<int>> len_idcs;
    int global_max;
    vector<int> num_nexts;

    int find_max(vector<string>& words, int len, int idx)
    {
        if(len == 16)
            return 1;
        
        if(num_nexts[idx] != -1)
            return num_nexts[idx];

        int ret = 1;
        for(int i = 0; i<len_idcs[len+1].size(); ++i)
        {
            int next_idx = len_idcs[len+1][i];
            int diff = 0;
            int idx0 = 0;
            int idx1 = 0;
            while(true)
            {
                if(words[idx][idx0] == words[next_idx][idx1])
                {
                    ++idx0;
                    ++idx1;
                }
                else
                {
                    ++idx1;
                    ++diff;
                    if(diff > 1)
                        break;
                }

                if(idx0 == len)
                    break;
            }
          
            if(diff <= 1)
                ret = max(ret, 1 + find_max(words, len+1, next_idx));
        }
        num_nexts[idx] = ret;
        global_max = max(global_max, ret);

        return ret;
    }

    int longestStrChain(vector<string>& words) 
    {
        len_idcs = vector<vector<int>>(17);
        global_max = 1;
        num_nexts = vector<int>(k, -1);
        int k = words.size();
        for(int i = 0; i<k; ++i)
        {
            auto& word = words[i];
            int len = word.length();
            len_idcs[len].emplace_back(i);
        }

        for(int i = 0; i<=16; ++i)
        {
            for(int j = 0; j<len_idcs[i].size(); ++j)
                find_max(words, i, len_idcs[i][j]);
        }
      
        return global_max;
    }
};
