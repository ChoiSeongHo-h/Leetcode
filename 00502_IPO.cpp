/*
https://leetcode.com/problems/ipo/
-> Accepted (Hard)
*/

class Solution 
{
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        vector<vector<int>> extended(profits.size(), vector<int>(2));
        for(int i = 0; i<profits.size(); ++i)
        {
            extended[i][0] = capital[i];
            extended[i][1] = profits[i];
        }

        sort(extended.begin(), extended.end());

        int idx_now = 0;
        int cnt = 0;
        priority_queue<int> pq;

        while(true)
        {
            int before_sz = pq.size();
            for(; idx_now<extended.size(); ++idx_now)
            {
                if(extended[idx_now][0] > w)
                    break;

                pq.emplace(extended[idx_now][1]);
            }
            if(pq.size() == before_sz)
                return w;

            while(!pq.empty())
            {
                w += pq.top();
                pq.pop();

                ++cnt;
                if(cnt == k)
                    return w;

                if(idx_now != extended.size() && extended[idx_now][0] <= w)
                    break;
            }
        }

        return w;
    }
};
