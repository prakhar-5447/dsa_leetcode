// https://leetcode.com/problems/reverse-string/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isVowel(char s)
    {
        if (s == 'a' || s == 'A' || s == 'e' || s == 'E' || s == 'i' || s == 'I' || s == 'o' || s == 'O' || s == 'u' || s == 'U')
            return true;
        return false;
    }

    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (isVowel(s[i]) && isVowel(s[j]))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if (isVowel(s[i]))
                j--;
            else if (isVowel(s[j]))
                i++;
            else
            {
                i++;
                j--;
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    string ans = s.reverseVowels("leetcode");
    for (int i = 0; i < ans.length(); i++)
    {
        cout << ans[i];
    }
}