// https : // leetcode.com/problems/palindrome-partitioning/description/

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
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> ans;
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), false));
        solve(dp, 0, s, res, ans);
        return res;
    }

    void solve(vector<vector<int>> &dp, int idx, string s, vector<vector<string>> &res, vector<string> &ans)
    {
        if (idx == s.length())
        {
            res.push_back(ans);
            return;
        }

        for (int i = 0; idx + i < s.length(); i++)
        {
            if (isPalindrome(dp, idx, i + idx, s))
                ans.push_back(findString(s, idx, idx + i));
            else
                continue;
            solve(dp, idx + i + 1, s, res, ans);
            ans.pop_back();
        }
    }

    bool isPalindrome(vector<vector<int>> &dp, int i, int j, string s)
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

    string findString(string s, int i, int j)
    {
        string temp;
        for (i; i <= j; i++)
        {
            temp.push_back(s[i]);
        }
        return temp;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> ans = s.partition("aab");
    f(i, 0, ans.size())
    {
        f(j, 0, ans[i].size())
        {
            c(ans[i][j]);
        }
        c(" ");
    }
}