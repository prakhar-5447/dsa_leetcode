// https://leetcode.com/problems/minimum-path-sum/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i < m - 1 && j < n - 1)
        {
            if (dp[i][j] == 0)
                dp[i][j] = min(grid[i][j] + minPathSum(grid, i + 1, j, m, n, dp), grid[i][j] + minPathSum(grid, i, j + 1, m, n, dp));
        }
        else if (i < m - 1)
        {
            if (dp[i][j] == 0)
                dp[i][j] = grid[i][j] + minPathSum(grid, i + 1, j, m, n, dp);
        }
        else if (j < n - 1)
        {
            if (dp[i][j] == 0)
                dp[i][j] = grid[i][j] + minPathSum(grid, i, j + 1, m, n, dp);
        }
        else
        {
            if (dp[i][j] == 0)
                dp[i][j] = grid[i][j];
        }

        return dp[i][j];
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        return minPathSum(grid, 0, 0, grid.size(), grid[0].size(), dp);
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution s;
    cout << s.minPathSum(arr) << endl;
}