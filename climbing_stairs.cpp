// https://leetcode.com/problems/climbing-stairs/description/

#include <iostream>

using namespace std;

// class Solution
// {
// public:
//     unsigned long int fact(int n, int s)
//     {
//         if (n == 0)
//             return 1;
//         unsigned long int res = 1;
//         for (int i = s; i <= n; i++)
//             res = res * i;
//         return res;
//     }

//     int nCr(int n, int r)
//     {
//         if (n - r > r)
//             return fact(n, n - r + 1) / fact(r, 2);
//         return fact(n, r + 1) / fact(n - r, 2);
//     }

//     int climbStairs(int n)
//     {
//         int a = n, result = 0, temp;

//         while (a >= 0)
//         {
//             temp = n - a;
//             if (n % 2 == 0)
//             {
//                 result += nCr(temp + a / 2, temp);
//             }
//             else
//             {
//                 temp++;
//                 result += nCr(temp + a / 2, temp);
//             }
//             a = a - 2;
//         }

//         return result;
//     }
// };

class Solution
{
public:
    int dp[46][46] = {0};
    int climbStairs(int n)
    {
        int a, result, temp, up, down;
        dp[2][1] = 2;
        dp[1][2] = 1;
        dp[2][3] = 1;

        for (int i = 1; i <= n; i++)
        {
            a = i;
            result = 0;
            while (a >= 0)
            {
                temp = i - a;
                if (i % 2 != 0)
                    temp++;
                up = temp + a / 2;
                down = temp;

                if (up == down || down == 0)
                {
                    dp[up][down] = 1;
                    result += 1;
                }
                else if (dp[up][down] != 0)
                    result += dp[up][down];
                else if (dp[up - 1][down] != 0)
                {
                    dp[up][down] = dp[up - 1][down] + dp[up - 1][down - 1];
                    result += dp[up][down];
                }
                else
                {
                    dp[up][down] = 1;
                    result += 1;
                }
                a = a - 2;
            }
        }

        return result;
    }
};

int main()
{
    int n = 45;
    Solution s;
    cout << s.climbStairs(n) << endl;
}