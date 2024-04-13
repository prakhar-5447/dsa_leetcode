// https://leetcode.com/problems/reverse-string-ii/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int n = s.length();
        if (k > n)
        {
            reverse(s.begin(), s.end());
            return s;
        }

        int j = 0;
        string ans;

        for (int i = 0; i < n; i += (2 * k))
        {
            string temp = s.substr(i, k);
            reverse(temp.begin(), temp.end());
            ans += temp;

            j += k;
            while (j < n && j < (i + 2 * k))
            {
                ans.push_back(s[j]);
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string ans = s.reverseStr("abcdefghijklmnopqrstuvwxyz",5);
    cout << ans << endl;
}