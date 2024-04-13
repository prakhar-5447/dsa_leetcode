// https://leetcode.com/problems/longest-palindromic-substring/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    bool solve(vector<vector<bool>> &dp, int i, int j, string &s)
    {
        if (i == j)
            return dp[i][j] = true;
        if (j - i == 1)
        {
            if (s[i] == s[j])
                return dp[i][j] = true;
            else
                return dp[i][j] = false;
        }
        if (s[i] == s[j] && dp[i + 1][j - 1] == true)
            return dp[i][j] = true;
        else
            return dp[i][j] = false;
    }

public:
    string longestPalindrome(string s)
    {
        int startIndex = 0;
        int maxlen = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int g = 0; g < s.size(); g++)
        {
            for (int i = 0, j = g; j < s.size(); i++, j++)
            {
                solve(dp, i, j, s);
                if (dp[i][j] == true)
                {
                    startIndex = i;
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        return s.substr(startIndex, maxlen);
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("aababa") << endl;
}