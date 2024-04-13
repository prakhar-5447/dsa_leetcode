// https://leetcode.com/problems/number-of-1-bits/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        if (n == 0)
            return 0;
        return n % 2 + hammingWeight(n / 2);
    }
};

int main()
{
    Solution s;
    cout << s.hammingWeight(uint32_t(00000000000000000000000000001011)) << endl;
}