/*
https://leetcode.com/problems/first-unique-character-in-a-string/
-> Accepted (Easy)
*/

class Solution 
{
public:
    int firstUniqChar(string s) 
    {
        vector<int> tb(26, 0);
        for(int i = 0; i<s.length(); ++i)
        {
            tb[s[i]-'a']++;
        }
        for(int i = 0; i<s.length(); ++i)
        {
            if(tb[s[i]-'a'] == 1)
                return i;
        }

        return -1;
    }
};
