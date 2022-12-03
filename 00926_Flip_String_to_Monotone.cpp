/*
https://leetcode.com/problems/flip-string-to-monotone-increasing/
-> Accepted (Medium)
*/

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        vector<int> l2rNum1(s.size()+1, 0);
        vector<int> r2lNum0(s.size()+1, 0);

        for(int i = 1; i<s.size()+1; i++)
        {
            l2rNum1[i] = l2rNum1[i-1];
            if(s[i-1] == '1')
                l2rNum1[i]++;
        }
        
        for(int i = s.size()-1; i>=0; i--)
        {
            r2lNum0[i] = r2lNum0[i+1];
            if(s[i] == '0')
                r2lNum0[i]++;
        }
        int ans = 10e6;
        for(int i = 0; i<s.size()+1; i++)
            ans = min(ans, l2rNum1[i] + r2lNum0[i]);
        
        return ans;
    }
};
