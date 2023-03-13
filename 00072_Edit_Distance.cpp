/*
https://leetcode.com/problems/edit-distance/
-> Accepted (Hard)
*/

class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        int sz1 = word1.size();
        int sz2 = word2.size();
        if(sz1 == 0)
            return sz2;
        if(sz2 == 0)
            return sz1;

        vector<vector<int>> tb(sz1+1, vector<int>(sz2+1, 0));
        for(int i = 0; i<sz1+1; ++i)
            tb[i][0] = i;

        for(int j = 0; j<sz2+1; ++j)
            tb[0][j] = j;

        for(int i = 1; i<sz1+1; ++i)
        {
            for(int j = 1; j<sz2+1; ++j)
            {
                if(word1[i-1] == word2[j-1])
                    tb[i][j] = tb[i-1][j-1];
                else
                    tb[i][j] = min(tb[i-1][j], min(tb[i][j-1], tb[i-1][j-1]))+1;
            }
        }

        return tb[sz1][sz2];
    }
};
