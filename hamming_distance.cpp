// https://leetcode.com/problems/hamming-distance/description/

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

    int hammingDistance(int x, int y)
    {
        return hammingWeight(x ^ y);
    }
};

int main()
{
    Solution s;
    cout << s.hammingDistance(1, 4) << endl;
}