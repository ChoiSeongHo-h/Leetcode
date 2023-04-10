/*
https://leetcode.com/problems/sort-characters-by-frequency/
-> Accepted (Medium)
*/

class Solution 
{
public:
    string frequencySort(string s) 
    {
        int a = 'a';
        int z = 'z';
        int A = 'A';
        int Z = 'Z';
        int zero = '0';
        vector<vector<int>> hist(26*2+10, vector<int>(2, 0));
        for(int i = 0; i<26; ++i)
            hist[i][1] = i+a;
        for(int i = 26; i<26*2; ++i)
            hist[i][1] = i-26+A;
        for(int i = 26*2; i<26*2+10; ++i)
            hist[i][1] = i-26*2+zero;

        for(int i = 0; i<s.length(); ++i)
        {
            if(a <= s[i] && s[i] <= z)
                ++hist[s[i]-a][0];
            else if(A <= s[i] && s[i] <= Z)
                ++hist[s[i]-A+26][0];
            else
                ++hist[s[i]-zero+26*2][0];
        }
        sort(hist.begin(), hist.end());
        
        string ans;
        for(int i = 26*2+10-1; i>=0; --i)
        {
            for(int j = 0; j<hist[i][0]; ++j)
                ans += hist[i][1];
        }

        return ans;
    }
};
