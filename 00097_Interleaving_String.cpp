/*
https://leetcode.com/problems/interleaving-string/
-> Accepted (Medium)
*/

class Solution 
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int s1Sz = s1.size();
        int s2Sz = s2.size();
        int s3Sz = s3.size();
        if(s1Sz+s2Sz != s3Sz)
            return false;
        if(s1Sz == 0 && s2==s3 || s2Sz == 0 && s1==s3)
            return true;
        
        vector<vector<bool>> table(s1Sz+1, vector<bool>(s2Sz+1, false));
        table[0][0] = true;
        for (int j = 1; j<s2Sz+1; j++)
        {
            if(table[0][j-1] == true && s2[j-1] == s3[j-1])
                table[0][j] = true;
        }
        for (int i = 1; i<s1Sz+1; i++)
        {
            if(table[i-1][0] == true && s1[i-1] == s3[i-1])
                table[i][0] = true;
        }
        
        for (int i = 1; i<s1Sz+1; i++)
        {
            for (int j = 1; j<s2Sz+1; j++)
            { 
                if(table[i][j-1] == true && s2[j-1] == s3[j+i-1] ||
                  table[i-1][j] == true && s1[i-1] == s3[j+i-1])
                {
                    table[i][j] = true;
                    if(i+j == s3.size())
                        return true;
                }
            }
        }
          
        return false;
    }
};
