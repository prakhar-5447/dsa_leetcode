// https://leetcode.com/problems/unique-paths-ii/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[i][j])
            return 0;

        if (i < m - 1 && j < n - 1)
        {
            if (dp[i][j] == 0)
                dp[i][j] = uniquePathsWithObstacles(i + 1, j, m, n, dp, obstacleGrid) + uniquePathsWithObstacles(i, j + 1, m, n, dp, obstacleGrid);
        }
        else if (i < m - 1)
        {
            if (dp[i][j] == 0)
                dp[i][j] = uniquePathsWithObstacles(i + 1, j, m, n, dp, obstacleGrid);
        }
        else if (j < n - 1)
        {
            if (dp[i][j] == 0)
                dp[i][j] = uniquePathsWithObstacles(i, j + 1, m, n, dp, obstacleGrid);
        }
        else
        {
            if (dp[i][j] == 0)
                dp[i][j] = 1;
        }

        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        return uniquePathsWithObstacles(0, 0, obstacleGrid.size(), obstacleGrid[0].size(), dp, obstacleGrid);
    }
};

int main()
{
    vector<vector<int>> arr = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution s;
    cout << s.uniquePathsWithObstacles(arr) << endl;
}