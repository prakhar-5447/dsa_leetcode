// https://leetcode.com/problems/power-of-three/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n == 1)
            return true;
        if (n < 3)
            return false;
        return n % 3 == 0 && isPowerOfThree(n / 3);
    }
};

int main()
{
    Solution s;
    cout << s.isPowerOfThree(90) << endl;
}