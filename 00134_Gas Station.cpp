/*
https://leetcode.com/problems/gas-station/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        vector<int> gap(gas.size());
        int net = 0;
        for (int i = 0; i< gas.size(); i++)
        {
            gap[i] = gas[i]-cost[i];
            net += gap[i];
        }
        if(net < 0)
            return -1;
        if(gap.size() == 1)
            return 0;
        
        int netL = 0;
        int netR = net;
        int bestIdx = 0;
        int bestNet = netR;
        for (int i = 0; i<gap.size(); i++)
        {        
            if (netR > bestNet)
            {
                bestNet = netR;
                bestIdx = i;
            }
            netL += gap[i];
            netR -= gap[i];
        }

        return bestIdx;
    }
};
