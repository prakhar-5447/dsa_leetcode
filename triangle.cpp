// https://leetcode.com/problems/triangle/description/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &dp, vector<vector<int>> &triangle, int i, int level, int size)
    {
        if (size == level)
            return triangle[level][i];

        if (dp[level][i] != INT_MIN)
            return dp[level][i];

        dp[level][i] = triangle[level][i] + min(minimumTotal(dp, triangle, i, level + 1, triangle.size() - 1), minimumTotal(dp, triangle, i + 1, level + 1, triangle.size() - 1));
        return dp[level][i];
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), INT_MIN));
        return minimumTotal(dp, triangle, 0, 0, triangle.size() - 1);
    }
};

int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution s;
    cout << s.minimumTotal(triangle) << endl;
}