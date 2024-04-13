// https://leetcode.com/problems/repeated-substring-pattern/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        if (s.length() == 1)
            return false;

        int patternSize = 1;
        for (int i = 0; i < s.length() - patternSize - 1; i++)
        {
            if (s[i] != s[i + patternSize])
            {
                patternSize++;
                i = 0;
            }
        }

        int count = patternSize;
        for (int i = patternSize; i < s.length(); i++)
        {
            if (count == 0)
                count = patternSize;
            count--;
            if (s[i] != s[i - patternSize])
                return false;
        }
        return (count == 0 || count == patternSize);
    }
};

int main()
{
    Solution s;
    cout << s.repeatedSubstringPattern("ababababababaababababababaababababababa") << endl;
}