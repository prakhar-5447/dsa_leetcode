// https://leetcode.com/problems/arranging-coins/description

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int arrangeCoins(int n)
    {
        int count = 0, i = 0;
        while (count <= n - ++i)
        {
            count += i;
        }
        return --i;
    }
};

int main()
{
    Solution s;
    cout << s.arrangeCoins(456556) << endl;
}