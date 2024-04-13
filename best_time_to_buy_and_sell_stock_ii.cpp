// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

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
    int maxProfit(vector<int> &prices)
    {
        vector<int> dp(prices.size() + 1, 0);
        return findProfit(prices, dp, 0);
    }

    int findProfit(vector<int> &prices, vector<int> &dp, int index)
    {
        if (index > prices.size() - 2)
            return 0;

        if (dp[index] != 0)
            return dp[index];

        for (int i = index + 1; i < prices.size(); i++)
        {
            if (prices[index] < prices[i])
            {
                int temp = prices[i] - prices[index];
                dp[index] = max(dp[index], temp + findProfit(prices, dp, i + 1));
            }
            else
                return dp[index] = max(dp[index], findProfit(prices, dp, i));
        }
        return dp[index];
    }
};

int main()
{
    vi a = {7, 1, 5, 3, 6, 4};
    Solution s;
    c(s.maxProfit(a));
}