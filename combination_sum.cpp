// https://leetcode.com/problems/combination-sum/description/

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
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        solve(res, ans, candidates, target, 0, candidates.size());
        return res;
    }

    void solve(vector<vector<int>> &res, vector<int> &ans, vector<int> &candidates, int target, int index, int len)
    {
        if (target == 0)
        {
            res.push_back(ans);
            return;
        }

        for (int i = index; i < len; i++)
        {
            if (candidates[i] > target)
                break;

            ans.push_back(candidates[i]);
            solve(res, ans, candidates, target - candidates[i], i, len);
            ans.pop_back();
        }
    }
};

int main()
{
    vi a = {2, 3, 6, 7};
    Solution s;
    vii ans = s.combinationSum(a, 7);
    f(i, 0, ans.size())
    {
        f(j, 0, ans[i].size())
        {
            c(ans[i][j]);
        }
        c(" ");
    }
}
