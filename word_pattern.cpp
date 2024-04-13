// https://leetcode.com/problems/word-pattern/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        int len = s.length();
        int patternLen = pattern.length();
        map<char, string> patternToString;
        map<string, char> stringToPattern;
        int i = 0, j = 0;

        for (; i < patternLen; i++)
        {
            string temp = "";
            if (j >= len)
                return false;

            for (; j < len && s[j] != ' '; j++)
            {
                temp += s[j];
            }
            j++;

            if (patternToString[pattern[i]] != "" && stringToPattern[temp])
            {
                if (temp != patternToString[pattern[i]] || pattern[i] != stringToPattern[temp])
                    return false;
            }
            else if (patternToString[pattern[i]] != "")
            {
                if (pattern[i] != stringToPattern[temp])
                    return false;
                patternToString[pattern[i]] = temp;
            }
            else if (stringToPattern[temp])
            {
                if (temp != patternToString[pattern[i]])
                    return false;
                stringToPattern[temp] = pattern[i];
            }
            else
            {
                stringToPattern[temp] = pattern[i];
                patternToString[pattern[i]] = temp;
            }
        }

        return j > len;
    }
};

int main()
{
    Solution s;
    cout << s.wordPattern("ab", "title home") << endl;
}