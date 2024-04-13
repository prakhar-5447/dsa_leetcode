// https://leetcode.com/problems/powx-n/description

#include <iostream>
#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long num = n;
        if (num < 0)
        {
            num = -1 * num;
        }
        while (num)
        {
            if (num % 2)
            {
                ans = ans * x;
                num = num - 1;
            }
            else
            {
                x = x * x;
                num = num / 2;
            }
        }
        if (n < 0)
            ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.myPow(2, 2) << endl;
}