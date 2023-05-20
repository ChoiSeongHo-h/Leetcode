/*
https://leetcode.com/problems/maximum-product-of-word-lengths/
-> Accepted (Medium)
*/

// vector
class Solution 
{
public:
    int maxProduct(vector<string>& words) 
    {
        int a = 'a';
        vector<vector<int>> tb(words.size(), vector<int>(26, 0));
        for(int i = 0; i<words.size(); ++i)
        {
            for(int j = 0; j<words[i].size(); ++j)
            {
                ++tb[i][words[i][j]-a];
            }
        }
        
        unsigned long ans = 0;
        for(int i = 0; i<words.size()-1; ++i)
        {
            for(int j = i+1; j<words.size(); ++j)
            {
                int overlap = 0;
                for(int k = 0; k<26; ++k)
                {
                    if(tb[i][k]*tb[j][k] != 0)
                    {
                        overlap = 1;
                        break;
                    }
                }

                if(!overlap)
                    ans = max(ans, words[i].length()*words[j].length());
            }
        }

        return (int)ans;
    }
};

//bit manipulation
class Solution 
{
public:
    int maxProduct(vector<string>& words) 
    {
        vector<int> bitmask(words.size());
        int maximum = 0;

        for(int i = 0; i < words.size(); i++)
        {
            for(auto c :  words[i])
                bitmask[i] |= 0x1 <<  (c - 'a');
        }

        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i + 1; j < words.size(); j++)
            {
                if(!(bitmask[i] & bitmask[j]))
                    maximum = max(maximum, int(words[i].size() * words[j].size()));
            }
        }

        return maximum;
    }
};
