/*
https://leetcode.com/problems/stone-game-vi/
-> Accepted (Medium)
*/

class Solution
{
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues)
    {
        if(aliceValues.size() == 1)
            return 1;
            
        vector<vector<int>> valuesVec(aliceValues.size(), vector<int>(3));
        for(int i = 0; i<valuesVec.size(); i++)
        {
            valuesVec[i][0] = aliceValues[i] + bobValues[i];
            valuesVec[i][1] = aliceValues[i];
            valuesVec[i][2] = bobValues[i];
        }
        
        sort(valuesVec.begin(), valuesVec.end());

        int aliceValue = 0;
        for(int i = valuesVec.size()-1; i>=0; i = i-2)
            aliceValue += valuesVec[i][1];
        
        int bobValue = 0;
        for(int i = valuesVec.size()-2; i>=0; i = i-2)
            bobValue += valuesVec[i][2];
        
        if(aliceValue > bobValue)
            return 1;
        if(aliceValue < bobValue)
            return -1;
        return 0;

    }
};
