/*
https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int longestPalindrome(vector<string>& words) 
    {
        char a = 'a';
        char z = 'z';
        array<array<int, 26>, 26> tb({array<int, 26>{0, }, });
        for(auto& word : words)
        {
            auto& i = word[0];
            auto& j = word[1];
            ++tb[i-a][j-a];
        } 

        int cnt = 0;
        for(int i = 0; i<25; i++)
        {
            for(int j = i+1; j<=25; j++)
            {
                if(tb[i][j] == 0)
                    continue;
                
                cnt += 2*min(tb[i][j], tb[j][i]);
            }
        }
        
        int evenDiag = 0;
        int hasOdd = 0;
        for(int i = 0; i<=25; i++)
        {
            if(tb[i][i] == 0)
                continue;
                
            if(tb[i][i] % 2 == 0)
                evenDiag += tb[i][i];
            else
            {
                evenDiag += tb[i][i]-1;
                hasOdd = 1;
            }
        }
        
        return 2*(cnt+evenDiag+hasOdd);
    }
};
