//accept

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
        {
            return -1;
        }
        if(gap.size() == 1)
        {
            return 0;
        }
        
        int netL = 0;
        int netR = net;
        int resIdx = 0;
        int resNet = netR;
        for (int i = 0; i<gap.size(); i++)
        {        
            if (netR > resNet)
            {
                resNet = netR;
                resIdx = i;
            }
            netL += gap[i];
            netR -= gap[i];
        }

        return resIdx;
    }
};
