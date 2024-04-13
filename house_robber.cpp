// https://leetcode.com/problems/house-robber/description/

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
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return solve(dp, nums, 0);
    }

    int solve(vector<int> &dp, vector<int> nums, int idx)
    {
        if (idx == nums.size() - 1)
            return nums[idx];

        if (idx >= nums.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        return dp[idx] = max(nums[idx] + solve(dp, nums, idx + 2), solve(dp, nums, idx + 1));
    }
};

int main()
{
    vi a = {2, 7, 9, 3, 1};
    Solution s;
    c(s.rob(a));
}