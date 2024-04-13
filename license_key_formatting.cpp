// https://leetcode.com/problems/license-key-formatting/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        string ans;
        int j = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '-')
                continue;

            if (j == k)
            {
                ans.append("-");
                j = 0;
            }

            if (s[i] >= 97 && s[i] <= 122)
            {
                char a = s[i] - 32;
                ans.push_back(a);
                j++;
            }
            else
            {
                ans.push_back(s[i]);
                j++;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    string ans = s.licenseKeyFormatting("asd-dasd", 2);
    for (int i = 0; i < ans.length(); i++)
    {
        cout << ans[i];
    }
}