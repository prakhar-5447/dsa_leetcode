// https://leetcode.com/problems/house-robber-ii/description/

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
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(nums.size(), -1);
        vector<int> robArray1(nums.begin(), nums.end() - 1), robArray2(nums.begin() + 1, nums.end());
        int maxi = solve(dp, robArray1, robArray1.size() - 1);

        for (int i = 0; i < nums.size(); i++)
            dp[i] = -1;

        return max(maxi, solve(dp, robArray2, robArray2.size() - 1));
    }

    int solve(vector<int> &dp, vector<int> nums, int idx)
    {

        if (idx == 0)
            return nums[idx];

        if (idx < 0)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        return dp[idx] = max(nums[idx] + solve(dp, nums, idx - 2), solve(dp, nums, idx - 1));
    }
};

int main()
{
    vi a = {1, 2, 3, 1};
    Solution s;
    c(s.rob(a));
}