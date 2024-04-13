// https://leetcode.com/problems/combinations/description/

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
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> ans;
        combinations(res, ans, n, k, 1);
        return res;
    }

    void combinations(vector<vector<int>> &res, vector<int> &ans, int n, int k, int start)
    {
        if (ans.size() == k)
        {
            res.push_back(ans);
            return;
        }

        for (int i = start; i <= n - k + ans.size() + 1; i++)
        {
            ans.push_back(i);
            combinations(res, ans, n, k, i + 1);
            ans.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vii ans = s.combine(4, 2);
    f(i, 0, ans.size())
    {
        f(j, 0, ans[i].size())
        {
            c(ans[i][j]);
        }
        c(" ");
    }
}