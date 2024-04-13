// https://leetcode.com/problems/ransom-note/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int temp[26] = {0};
        int len1 = magazine.length();
        int len2 = ransomNote.length();
        int i;

        if (len1 < len2)
            return false;

        for (i = 0; i < len1; i++)
        {
            temp[magazine[i] - 'a']++;
        }

        for (i = 0; i < len2; i++)
        {
            if (temp[ransomNote[i] - 'a'] > 0)
                temp[ransomNote[i] - 'a']--;
            else
                return false;
        }

        return true;
    }
};

int main()
{
    Solution s;
    cout << s.canConstruct("aa", "aab") << endl;
}