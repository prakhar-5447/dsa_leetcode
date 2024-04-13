// https://leetcode.com/problems/valid-anagram/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        map<char, int> temp;

        int sLen = s.length();
        int tLen = t.length();

        if (tLen != sLen)
            return false;

        for (int i = 0; i < sLen; i++)
        {
            temp[s[i]] += 1;
            temp[t[i]] -= 1;
        }

        for (int i = 0; i <= 26; i++)
        {
            if (temp['a' + i] != 0)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    cout << sol.isAnagram("anagram", "nagaram") << endl;
}