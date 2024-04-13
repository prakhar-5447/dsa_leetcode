// https://leetcode.com/problems/first-unique-character-in-a-string/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int temp[26]={0};
        int len = s.length();

        for (int i = 0; i < len; i++)
        {
            temp[s[i] - 'a']++;
        }

        for (int i = 0; i < len; i++)
        {

            if (temp[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.firstUniqChar("loveleetcode") << endl;
}