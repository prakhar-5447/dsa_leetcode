// https://leetcode.com/problems/ugly-number/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isUgly(int n)
    {
        if (n == 1)
            return true;

        if (n < 1)
            return false;

        while (n % 2 == 0)
        {
            n /= 2;
        }
        while (n % 3 == 0)
        {
            n /= 3;
        }
        while (n % 5 == 0)
        {
            n /= 5;
        }
        return (n == 1);
    }
};

int main()
{
    Solution s;
    cout << s.isUgly(14) << endl;
}