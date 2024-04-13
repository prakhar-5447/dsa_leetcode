// https://leetcode.com/problems/restore-ip-addresses/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        restore(res, s, "", 0, 4);
        return res;
    }

    void restore(vector<string> &res, string &s, string c, int index, int octetNo)
    {
        if (index == s.length() && octetNo == 0)
        {
            c.pop_back();
            res.push_back(c);
            return;
        }

        if (octetNo == 0)
            return;

        int val = 0;
        for (int i = index; i < s.length(); i++)
        {
            if (i != index && s[index] == '0')
                break;
            int x = s[i] - 48;
            val = val * 10 + x;
            if (val <= 255)
            {
                c.push_back(s[i]);
                c.push_back('.');
                restore(res, s, c, i + 1, octetNo - 1);
                c.pop_back();
            }
            else
                return;
        }
    }
};

int main()
{
    Solution s;
    vector<string> ans = s.restoreIpAddresses("101023");
    f(i, 0, ans.size())
        c(ans[i]);
}