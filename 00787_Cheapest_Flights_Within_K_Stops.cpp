/*
https://leetcode.com/problems/cheapest-flights-within-k-stops/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<unordered_map<int, int>> city_price_map(n);
        for(int i = 0; i<flights.size(); i++)
        {
            int s = flights[i][0];
            int d = flights[i][1];
            int p = flights[i][2];
            city_price_map[s][d] = p;
        }
        
        queue<array<int, 2>> city_price_q;
        for(auto city_price : city_price_map[src])
            city_price_q.emplace(array<int, 2>{city_price.first, city_price.second});
        
        int depth = 0;
        int ans = 10e7;
        while(!city_price_q.empty())
        {
            int sz = city_price_q.size();
            unordered_map<int, int> next_city_price_map;
            while(sz--)
            {
                int city = city_price_q.front()[0];
                int price = city_price_q.front()[1];
                city_price_q.pop();
                
                if(price > ans)
                    continue;
                
                if(city == dst)
                    ans = min(ans, price);
                
                for(auto city_price : city_price_map[city])
                {
                    if(next_city_price_map.find(city_price.first) == next_city_price_map.end())
                        next_city_price_map[city_price.first] = 10e7;
                    
                    int origin = next_city_price_map[city_price.first];
                    next_city_price_map[city_price.first] = min(origin, city_price.second+price);
                }
            }
            depth++;
            if(depth == k+1)
                break;

            for(auto next_city_price : next_city_price_map)
                city_price_q.emplace(array<int, 2>{next_city_price.first, next_city_price.second});
        }
        if (ans == 10e7)
            return -1;
            
        return ans;
    }
};
