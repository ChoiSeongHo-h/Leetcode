/*
https://leetcode.com/problems/word-break-ii/submissions/
-> Accepted (Hard)
*/

class Solution 
{
public:
    vector<vector<vector<int>>> dp;
    void find_ans(int s_idx, vector<vector<int>> &tb, vector<string> &wordDict, vector<vector<int>> &ans_idcs, int word_idx, vector<int> &local)
    {
        auto &word = wordDict[word_idx];
        int next_s_idx = s_idx+word.length();
        if(next_s_idx == tb.size())
        {
            local.emplace_back(word_idx);
            ans_idcs.emplace_back(local);
            local.pop_back();
            return;
        }

        if(!dp[s_idx][word_idx].empty())
        {
            local.emplace_back(word_idx);
            for(int i = dp[s_idx][word_idx][0]; i<dp[s_idx][word_idx][1]; ++i)
            {
                ans_idcs.emplace_back(local);
                for(int j = dp[s_idx][word_idx][2]; j<ans_idcs[i].size(); ++j)
                    ans_idcs.back().emplace_back(ans_idcs[i][j]);
            }
            local.pop_back();
            return;
        }

        int ans_begin = ans_idcs.size();
        for(int i = 0; i<tb[next_s_idx].size(); ++i)
        {
            int next_word_idx = tb[next_s_idx][i];
            local.emplace_back(word_idx);
            find_ans(next_s_idx, tb, wordDict, ans_idcs, next_word_idx, local);
            local.pop_back();
        }
        int ans_end = ans_idcs.size();
        dp[s_idx][word_idx].emplace_back(ans_begin);
        dp[s_idx][word_idx].emplace_back(ans_end);
        dp[s_idx][word_idx].emplace_back(local.size()+1);
        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        vector<vector<int>> tb(s.size());
        dp = vector<vector<vector<int>>>(s.size(), vector<vector<int>>(wordDict.size()));
        for(int i = 0; i<s.length(); ++i)
        {
            for(int j = 0; j<wordDict.size(); ++j)
            {
                auto &word = wordDict[j];
                if(i+word.length() > s.length())
                    continue;

                int contain = 1;
                for(int k = 0; k<word.length(); ++k)
                {
                    if(s[i+k] != word[k])
                    {
                        contain = 0;
                        break;
                    }
                }
                
                if(contain)
                    tb[i].emplace_back(j);
            }
        }

        vector<vector<int>> ans_idcs;
        for(int i = 0; i<tb[0].size(); ++i)
        {
            vector<int> local;
            find_ans(0, tb, wordDict, ans_idcs, tb[0][i], local);
        }

        vector<string> ans;
        for(int i = 0; i<ans_idcs.size(); ++i)
        {
            ans.emplace_back("");
            for(int j = 0; j<ans_idcs[i].size(); ++j)
                ans.back() += wordDict[ans_idcs[i][j]] + " ";

            ans.back().pop_back();
        }
      
        return ans;
    }
};
