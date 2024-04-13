// https://leetcode.com/problems/nim-game/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canWinNim(int n)
    {
        return n % 4;
    }
};

int main()
{
    Solution s;
    cout << s.canWinNim(100) << endl;
}