// https://leetcode.com/problems/wildcard-matching/description/

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
    bool isMatch(string s, string p)
    {

        int pn = p.size(), sn = s.size();
        vector<vector<int>> dp(sn + 1, vector<int>(pn + 1, -1));
        return isMatch(sn, s, pn, p, dp);
    }

    bool isMatch(int i, string &s, int j, string &p, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return true;

        if (j == 0)
            return false;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == 0)
        {
            while (j > 0)
            {
                if (p[j - 1] != '*')
                    return dp[i][j] = false;
                j--;
            }
            return dp[i][j] = 1;
        }

        bool res = false;
        if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
            res = isMatch(i - 1, s, j - 1, p, dp);
        else if (p[j - 1] == '*')
            res = isMatch(i, s, j - 1, p, dp) | isMatch(i - 1, s, j, p, dp);
        return dp[i][j] = res;
    }
};

int main()
{
    Solution s;
    c(s.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b"));
}