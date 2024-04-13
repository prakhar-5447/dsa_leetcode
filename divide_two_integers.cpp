// https://leetcode.com/problems/divide-two-integers/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
     
        long int dv = abs(dividend);
        long int ds = abs(divisor);
        int count = 0;
        while (ds <= dv)
        {
            long int val = ds, temp = 1;
            while (val <= dv - val)
            {
                val += val;
                temp += temp;
            }
            count += temp;
            dv -= val;
        }
        
        if((dividend<0&&divisor>0) || (dividend>0&&divisor<0)) return -count;

        return count;
    }
};

int main()
{
    Solution s;
    cout << s.divide(10, 3) << endl;
}