// https://leetcode.com/problems/combination-sum-iii/description/

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
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> ans;
        solve(res, ans, k, n, 1);
        return res;
    }

    void solve(vector<vector<int>> &res, vector<int> &ans, int k, int n, int idx)
    {
        if (n == 0 && k == 0)
            res.push_back(ans);

        if (n == 0 || k == 0)
            return;

        for (int i = idx; i < 10; i++)
        {
            ans.push_back(i);
            solve(res, ans, k - 1, n - i, i + 1);
            ans.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vii ans = s.combinationSum3(3, 10);
    f(i, 0, ans.size())
    {
        f(j, 0, ans[i].size())
            c(ans[i][j]);
        c(" ");
    }
}