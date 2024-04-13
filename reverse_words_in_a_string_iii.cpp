// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int start = 0;
        int len = s.length() - 1;
        for (int i = 0; i <= len; i++)
        {
            if (s[i] == ' ')
            {
                int end = i - 1;
                while (start < end)
                {
                    swap(s[end--], s[start++]);
                }
                start = i + 1;
            }
        }
        while (start < len)
        {
            swap(s[start++], s[len--]);
        }
        return s;
    }
};

int main()
{
    Solution s;
    string ans = s.reverseWords("Let's take LeetCode contest");
    cout << ans << endl;
}