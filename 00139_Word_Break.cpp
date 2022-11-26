/*
https://leetcode.com/problems/word-break/
-> Accepted (Medium)
*/

class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        vector<bool> possibles(s.length()+1, 0);
        possibles[0] = true;
        for(int idx = 0; idx < s.length(); ++idx)
        {
            if(possibles[idx+1])
                continue;
                
            for(auto& word : wordDict)
            {
                if(idx+1 < word.length())
                    continue;
                if(s.substr(idx+1-word.length(), word.length()).find(word) == string::npos)
                    continue;

                possibles[idx+1] = possibles[idx+1] + possibles[idx+1-word.length()];
            }
        }
        return possibles.back();
    }
};
