// https://leetcode.com/problems/longest-palindromic-substring/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        string s_new = s + "#" + rev;
        int n_new = s_new.size();
        vector<int> lps(n_new, 0);
        int t = 0;
        for (int i = 1; i < n_new; i++)
        {
            t = lps[i - 1];

            while (t > 0 && s_new[i] != s_new[t])
                t = lps[t - 1];

            if (s_new[i] == s_new[t])
                ++t;

            lps[i] = t;
        }
        return rev.substr(0, n - lps[n_new - 1]) + s;
    }
};

int main()
{
    Solution s;
    cout << s.shortestPalindrome("aababa") << endl;
}