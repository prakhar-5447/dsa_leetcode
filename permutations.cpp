// https://leetcode.com/problems/permutations/description/

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
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        permutation(res, nums, 0);
        return res;
    }

    void permutation(vector<vector<int>> &res, vector<int> &nums, int idx)
    {
        if (idx >= nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[i], nums[idx]);
            permutation(res, nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }
};

int main()
{
    vi a = {1, 2, 3};
    Solution s;
    vii ans = s.permute(a);
    f(i, 0, ans.size())
    {
        f(j, 0, ans[i].size())
        {
            c(ans[i][j]);
        }
        c(" ");
    }
}