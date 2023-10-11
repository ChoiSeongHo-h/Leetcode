/*
https://leetcode.com/problems/valid-perfect-square/
-> Accepted (Easy)
*/

class Solution 
{
public:
    bool isPerfectSquare(int num) 
    {
        if(num == 1)
            return true;

        int l = 1;
        int r = num;
        while(l<r)
        {
            unsigned long long sum = (unsigned long long)l+(unsigned long long)r;
            unsigned long long mid = sum/2;
            unsigned long long product = mid*mid;
            unsigned long long num_temp = num;
            if(product < num_temp)
                l = mid+1;
            else if(product > num_temp)
                r = mid;
            else
                return true;
        }

        return false;
    }
};
