/*
https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
-> Accepted (Medium)
*/

bool cmp(int a, int b)
{
    return a>b;
}

class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> nums(26, 0);
        for(int i = 0; i<s.length(); i++)
            nums[s[i]-'a']++;

        sort(nums.begin(), nums.end(), cmp);
        
        int cnt = 0;
        auto it0 = nums.begin();
        auto it1 = nums.begin()+1;
        while(it1 != nums.end() && !(*it0 == 0 && *it1 == 0))
        {
            if(*it0 <= *it1)
            {
                *it1 = *it1-1;
                cnt++;
                if(*it1 == 0)
                {
                    it0++;
                    it1++;
                }
                continue;
            }
            it0++;
            it1++;
        }

        return cnt;
    }
};
