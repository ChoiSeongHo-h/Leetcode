/*
https://leetcode.com/problems/decode-string/
-> Accepted (Medium)
*/

class Solution 
{
public:
    string decodeString(string s) 
    {
        string ans;
        int num = 0;
        int num_temp = 0;
        int base = 10;
        int zero = '0';
        int before = -1;
        string temp;
        for(int i = 0; i<s.length(); ++i)
        {
            char c = s[i];
            if('0'<=c && c<='9')
            {
                num_temp = num_temp*base + c-zero;
                continue;
            }

            if(c == '[')
            {
                before = i+1;
                num = num_temp;
                num_temp = 0;
                continue;
            }

            if(c == ']')
            {
                if(before == -1)
                    continue;

                for(int j = 0; j<before-1; ++j)
                    temp += s[j];
                while(!temp.empty() && '0' <= temp.back() && temp.back() <= '9')
                    temp.pop_back();

                for(int j = 0; j<num; ++j)
                {
                    for(int k = before; k<i; ++k)
                        temp += s[k];
                }
                for(int j = i+1; j<s.length(); ++j)
                    temp += s[j];

                before = -1;
                num = 0;
                num_temp = 0;
                s = temp;
                temp = string();
                i = -1;
            }
        }

        return s;
    }
};
