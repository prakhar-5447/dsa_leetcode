// https://leetcode.com/problems/sqrtx/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int mySqrt(int n)
    {
        int x = n, y = 1;
        while (x - y > 0)
        {
            x = y + (x - y) / 2;
            y = n / x;
        }
        return x;
    }
};

int main()
{
    Solution s;
    cout << s.mySqrt(64) << endl;
}