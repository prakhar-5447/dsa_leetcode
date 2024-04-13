// https://leetcode.com/problems/number-complement/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findComplement(int num)
    {
        int mask = 1, temp = num;

        while (num != 1)
        {
            mask = mask << 1 | 1;
            num /= 2;
        }

        return mask ^ temp;
    }
};

int main()
{
    Solution s;
    cout << s.findComplement(5) << endl;
}