/*
https://leetcode.com/problems/cheapest-flights-within-k-stops/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<unordered_map<int, int>> priceMaps(n);
        for(int i = 0; i<flights.size(); i++)
        {
            int s = flights[i][0];
            int d = flights[i][1];
            int p = flights[i][2];
            priceMaps[s][d] = p;
        }
        
        queue<array<int, 2>> idxPriceQ;
        for(auto i : priceMaps[src])
            idxPriceQ.emplace(array<int, 2>{i.first, i.second});
        
        int depth = 0;
        int ans = 10e7;
        bool isFin = false;
        while(!idxPriceQ.empty())
        {
            int qSz = idxPriceQ.size();
            unordered_map<int, int> tempPaths;
            while(qSz--)
            {
                int idx = idxPriceQ.front()[0];
                int prc = idxPriceQ.front()[1];
                idxPriceQ.pop();
                
                if(prc > ans)
                    continue;
                
                if(idx == dst)
                    ans = min(ans, prc);
                
                if(depth == k)
                    isFin = true;
                
                if(priceMaps.size() == 0)
                    continue;
                
                for(auto i : priceMaps[idx])
                {
                    if(tempPaths.find(i.first) == tempPaths.end())
                        tempPaths[i.first] = 10e7;
                    
                    tempPaths[i.first] = min(tempPaths[i.first], i.second+prc);
                }

            }
            depth++;
            for(auto i : tempPaths)
                idxPriceQ.emplace(array<int, 2>{i.first, i.second});
                
            if(isFin)
                break;
        }
        
        if (ans == 10e7)
            return -1;
            
        return ans;
    }
};
