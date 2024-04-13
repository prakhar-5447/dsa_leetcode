// https://leetcode.com/problems/counting-bits/description/

#include <bits/stdc++.h>

using namespace std;

int INF = 1e5 + 1;
vector<int> dp(INF, INF);

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 0; i <= n; i++)
        {
            if (dp[i] == INF)
                dp[i] = (i % 2) + dp[i / 2];
            ans.push_back(dp[i]);
        }

        return ans;
    }
};

int main()
{
    int row = 2;
    Solution s;

    vector<int> result = s.countBits(row);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}