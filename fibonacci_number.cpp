// https://leetcode.com/problems/fibonacci-number/description/

#include <iostream>

using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        int result = 0, n1 = 0, n2 = 1;
        for (int i = 1; i <= n; i++)
        {
            result = n1 + n2;
            n2 = n1;
            n1 = result;
        }

        return result;
    }
};

int main()
{
    Solution s;
    cout << s.fib(23) << endl;
}