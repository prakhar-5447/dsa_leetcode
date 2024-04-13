// https://leetcode.com/problems/power-of-four/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n == 1)
            return true;
        if (n < 1)
            return false;
        if (n & n - 1)
        {
            return false;
        }
        int count = 0;
        while (n)
        {
            count++;
            n = n >> 1;
        }
        return count % 2;
    }
};


int main()
{
    Solution s;
    cout << s.isPowerOfFour(64) << endl;
}