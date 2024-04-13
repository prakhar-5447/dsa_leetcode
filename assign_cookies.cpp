// https://leetcode.com/problems/assign-cookies/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i = 0, j = 0;
        while (i < g.size() && j < s.size())
        {
            if (s[j] >= g[i])
            {
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};

int main()
{
    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 1};
    Solution s;
    cout << s.findContentChildren(a, b) << endl;
}