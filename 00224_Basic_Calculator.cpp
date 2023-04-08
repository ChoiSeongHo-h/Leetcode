/*
https://leetcode.com/problems/basic-calculator/
-> Accepted (Hard)
*/

class Solution 
{
public:
    int calculate(string s) 
    {
        string s_temp;
        for(int i = 0; i<s.length(); ++i)
        {
            if(s[i] == ' ')
                continue;

            s_temp += s[i];
        }
        s = s_temp;

        s_temp.clear();
        if(s[0] != '0')
            s_temp += s[0];
        for(int i = 1; i<s.length(); ++i)
        {
            if(s[i] == '0' && !s_temp.empty() && !('0' <= s_temp.back() && s_temp.back() <= '9'))
                continue;

            s_temp += s[i];
        }
        s = s_temp;

        s_temp.clear();
        for(int i = 0; i<s.length(); ++i)
        {
            if((s[i] == '+' || s[i] == '-') && (i == s.length()-1 || i+1<s.length() && (s[i+1] == ')' || s[i+1] == '+' || s[i+1] == '-')))
                continue;

            s_temp += s[i];
        }
        s = s_temp;

        stack<int> st;
        vector<int> states(s.length(), 0);
        if(s[0] == '(')
        {
            states[0] = 1;
            st.emplace(0);
        }
        for(int i = 1; i<s.length(); ++i)
        {
            if(s[i] == '(')
            {
                st.emplace(i);
                if(s[i-1] == '+')
                    states[i] = 1;
            }
            else if(s[i] == ')')
            {
                int idx_prev = st.top();
                int state_prev = states[idx_prev];
                states[i] = state_prev;
                st.pop();
            }
        }

        s_temp.clear();
        for(int i = 0; i<s.length(); ++i)
        {
            if(states[i] == 1)
                continue;
            
            s_temp += s[i];
        }
        s = s_temp;

        vector<int> degrees(s.length(), 0);
        for(int i = 1; i<s.length(); ++i)
        {
            if(s[i] == '(' && s[i-1] == '-')
                degrees[i] = degrees[i-1]+1;
            else if(s[i] == ')')
                degrees[i] = degrees[i-1]-1;
            else
                degrees[i] = degrees[i-1];
        }

        int ans = 0;
        int local_num = 0;
        int zero = '0';
        for(int i = 0; i<s.length(); ++i)
        {
            if('0' <= s[i] && s[i] <= '9')
            {
                local_num *= 10;
                if(local_num >= 0)
                    local_num += s[i]-zero;
                else
                    local_num -= s[i]-zero;
                if(i-1 >= 0 && s[i-1] == '-')
                    local_num *= -1;
                if(i+1 < s.length() && '0' <= s[i+1] && s[i+1] <= '9')
                    continue;
            }
            else
                local_num = 0;

            if('0' <= s[i] && s[i] <= '9')
            {
                if(degrees[i]%2 == 1)
                    local_num *= -1;
                ans += local_num;
            }
        }

        return ans;
    }
};
