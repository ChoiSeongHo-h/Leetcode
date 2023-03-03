/*
https://leetcode.com/problems/2-keys-keyboard/
-> Accepted (Medium)
*/

// dp 2d
class Solution 
{
public:
    int nn;
    vector<vector<int>> tb;
    
    int copy_A(int num_has, int num_cp, int cnt_before)
    {
        int num_paste = paste_A(num_has, num_has, cnt_before+1);
        return num_paste;
    }

    int paste_A(int num_has, int num_cp, int cnt_before)
    {
        int num_now = num_has+num_cp;
        if(nn == num_now)
            return cnt_before+1;
        if(nn < num_now)
            return INT_MAX;
        
        if(tb[num_now][num_cp] == -1)
        {
            int num_copy = copy_A(num_now, num_cp, cnt_before+1);
            int num_paste = paste_A(num_now, num_cp, cnt_before+1);
            tb[num_now][num_cp] = min(num_copy, num_paste);
        }
        return tb[num_now][num_cp];
    }

    int minSteps(int n) 
    {
        if(n == 1)
            return 0;

        nn = n;
        tb = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        int ans = copy_A(1, 0, 0);
        return ans;
    }
};

// dp 1d
class Solution
{
public:
    int minSteps(int n)
    {
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 0;
        for(int i=2; i<=n; ++i)
        {
            dp[i] = i;
            for(int j = i/2; j>2; --j)
            {
                if(i%j == 0)
                {
                    dp[i] = dp[j] + i/j;
                    break;
                }
            }
        }
        return dp[n];
    }
};
