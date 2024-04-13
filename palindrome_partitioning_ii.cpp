// https : // leetcode.com/problems/palindrome-partitioning-ii/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
public:
    int minCut(string s)
    {
        int n = s.length();
        vector<vector<int>> d = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        d[n][n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            d[i][i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (i == j - 1)
                        d[i][j] = 1;
                    else
                        d[i][j] = d[i + 1][j - 1];
                }
            }
        }
        vector<int> dp2 = vector<int>(n + 1, n + 1);
        dp2[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (d[i][n - 1])
            {
                dp2[i] = 1;
                continue;
            }
            for (int j = i; j < n; j++)
            {
                if (d[i][j])
                    dp2[i] = min(dp2[j + 1] + 1, dp2[i]);
            }
        }
        return dp2[0] - 1;
    }
};

int main()
{
    Solution s;
    c(s.minCut("aab"));
}