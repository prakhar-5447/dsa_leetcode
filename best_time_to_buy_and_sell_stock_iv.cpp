// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

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
    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, -1));
        return findProfit(prices, dp, 0, 0, k);
    }

    int findProfit(vector<int> &prices, vector<vector<int>> &dp, int index, int count, int k)
    {
        if (index == prices.size() || count > 2 * k)
            return 0;

        if (dp[index][count] != -1)
            return dp[index][count];

        int profit = 0;
        if (count % 2 == 0)
        {
            int take = -prices[index] + findProfit(prices, dp, index + 1, count + 1, k);
            int notTake = 0 + findProfit(prices, dp, index + 1, count, k);
            profit = max(take, notTake);
        }
        else
        {
            int take = prices[index] + findProfit(prices, dp, index + 1, count + 1, k);
            int notTake = 0 + findProfit(prices, dp, index + 1, count, k);
            profit = max(take, notTake);
        }
        return dp[index][count] = profit;
    }
};

int main()
{
    vi a = {14, 9, 10, 12, 4, 8, 1, 16};
    Solution s;
    c(s.maxProfit(4, a));
}