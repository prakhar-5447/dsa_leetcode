    // https://leetcode.com/problems/decode-ways/description/

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
        int numDecodings(string s)
        {
            vector<int> dp(s.length() + 1, -1);
            return solve(dp, s, 0);
        }

        int solve(vector<int> &dp, string s, int index)
        {
            if (dp[index] != -1)
                return dp[index];

            if (index >= s.length())
                return 1;

            int pos = 0;
            int x = 0;
            for (int i = index; i < s.length(); i++)
            {
                x = x * 10 +  (s[i] - 48);
                if (x && x <= 26)
                    pos += solve(dp, s, i + 1);
                else
                    return dp[index] = pos;
            }
            return dp[index] = pos;
        }
    };

    int main()
    {
        Solution s;
        c(s.numDecodings("111111111111111111111111111111111111111111111"));
    }