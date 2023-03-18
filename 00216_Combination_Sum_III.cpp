/*
https://leetcode.com/problems/combination-sum-iii/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> mask(9, 0);
        for(int i = 8; i>=9-k; --i)
            mask[i] = 1;

        vector<vector<int>> ans;
        do
        {
            int sum = 0;
            vector<int> partial;
            for(int i = 0; i<mask.size(); ++i)
            {
                if(mask[i] == 0)
                    continue;

                int num = nums[i];
                partial.emplace_back(num);
                sum += num;
            }
            if(sum == n)
                ans.emplace_back(partial);

        }while(next_permutation(mask.begin(), mask.end()));
        
        return ans;
    }
};
