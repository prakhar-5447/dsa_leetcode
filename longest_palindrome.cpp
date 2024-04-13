// https://leetcode.com/problems/longest-palindrome/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int dp[52] = {0};
        int len = s.length();
        int count = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] >= 97 && s[i] <= 122)
            {
                if (dp[s[i] - 'a'] == 0)
                    dp[s[i] - 'a']++;
                else
                {
                    dp[s[i] - 'a']--;
                    count = count + 2;
                }
            }
            else
            {
                if (dp[s[i] - 'A' + 26] == 0)
                    dp[s[i] - 'A' + 26]++;
                else
                {
                    dp[s[i] - 'A' + 26]--;
                    count = count + 2;
                }
            }
        }
        if (count == len)
            return count;
        return count + 1;
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("abccccdd") << endl;
}