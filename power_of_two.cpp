// https://leetcode.com/problems/power-of-two/description/

#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n < 1)
            return false;
        return (n && !(n & n - 1));
    }
};

int main()
{
    Solution s;
    cout << s.isPowerOfTwo(5) << endl;
}