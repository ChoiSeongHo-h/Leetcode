/*
https://leetcode.com/problems/concatenated-words/
-> Accepted (Hard)
*/

class Solution 
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        unordered_set<string> uset;
        for(auto &word : words)
            uset.emplace(word);

        vector<string> ans;
        for(int i = 0; i<words.size(); ++i)
        {
            auto &word = words[i];
            vector<int> dp(word.length()+1, 0);
            dp[0] = 1;
          
            for(int l = 0; l<word.length(); ++l)
            {
                string target;
                for(int len = 1; l+len <= word.length(); ++len)
                {
                    int r = l+len-1;
                    target += word[r];
                    if(dp[r+1] == 1)
                        continue;

                    auto it = uset.find(target);
                    if(it == uset.end())
                        continue;
                    
                    if(dp[l] == 1 && len != word.length())
                        dp[r+1] = 1;
                }
            }
          
            if(dp.back() == 1)
                ans.emplace_back(word);
        }

        return ans;
    }
};
