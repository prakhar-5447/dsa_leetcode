// https://leetcode.com/problems/find-the-difference/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int sLen = s.length();
        int result = 0, i;

        for (i = 0; i < sLen; i++)
        {
            result ^= (s[i] ^ t[i]);
        }
        result ^= t[i];

        return result;
    }
};

int main()
{
    string s1 = "abcd", s2 = "abcde";
    Solution s;
    cout << s.findTheDifference(s1, s2) << endl;
}