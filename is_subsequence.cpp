// https://leetcode.com/problems/is-subsequence/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int tLen = t.length();
        int sLen = s.length();
        int i, j;

        for (i = 0, j = 0; i < sLen, j < tLen; j++)
        {
            if (s[i] == t[j])
                i++;
        }

        return i == sLen;
    }
};

int main()
{
    string s1 = "abc", s2 = "abc";
    Solution s;
    cout << s.isSubsequence(s1, s2) << endl;
}