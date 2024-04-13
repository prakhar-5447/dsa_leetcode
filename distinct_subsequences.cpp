// https://leetcode.com/problems/distinct-subsequences/description/

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
    int numDistinct(string s, string t)
    {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        if (s.length() < t.length())
            return 0;
        return solve(s, t, s.length() - 1, t.length() - 1, dp);
    }

    int solve(string s, string t, int i, int j, vector<vector<int>> &dp)
    {
        if (j < 0)
            return 1;

        if (i < 0 || i < j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = solve(s, t, i - 1, j - 1, dp) + solve(s, t, i - 1, j, dp);

        return dp[i][j] = solve(s, t, i - 1, j, dp);
    }
};

int main()
{
    Solution s;
    c(s.numDistinct("babgbag", "bag"));
}