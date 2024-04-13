// https://leetcode.com/problems/reverse-bits/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        int count = 31;
        uint32_t res = 0;
        while (n > 0)
        {
            if (n % 2 == 0)
            {
                count--;
                n /= 2;
                continue;
            }
            res += (n % 2) * pow(2, count);
            n /= 2;
            count--;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.reverseBits(uint32_t(00000000000000000000000000001011)) << endl;
}
