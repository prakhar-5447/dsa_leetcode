// https://leetcode.com/problems/subsets/description/

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
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> ans;
        res.push_back(ans);
        createSet(res, ans, nums, 0);
        return res;
    }

    void createSet(vector<vector<int>> &res, vector<int> &ans, vector<int> nums, int start)
    {
        if (ans.size())
            res.push_back(ans);
        for (int i = start; i < nums.size(); i++)
        {
            ans.push_back(nums[i]);
            createSet(res, ans, nums, i + 1);
            ans.pop_back();
        }
    }
};

int main()
{
    vi a = {1, 2, 3};
    Solution s;
    vii ans = s.subsets(a);
    f(i, 0, ans.size())
    {
        f(j, 0, ans[i].size())
        {
            c(ans[i][j]);
        }
        c(" ");
    }
}