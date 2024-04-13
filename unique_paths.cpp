// https://leetcode.com/problems/unique-paths/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePaths(int i, int j, int m, int n, vector<vector<int>> &dp)
    {

        if (i < m - 1 && j < n - 1)
        {
            if (dp[i][j] == 0)
                dp[i][j] = uniquePaths(i + 1, j, m, n, dp) + uniquePaths(i, j + 1, m, n, dp);
        }
        else if (i < m - 1)
        {
            if (dp[i][j] == 0)
                dp[i][j] = uniquePaths(i + 1, j, m, n, dp);
        }
        else if (j < n - 1)
        {
            if (dp[i][j] == 0)
                dp[i][j] = uniquePaths(i, j + 1, m, n, dp);
        }
        else
        {
            if (dp[i][j] == 0)
                dp[i][j] = 1;
        }

        return dp[i][j];
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return uniquePaths(0, 0, m, n, dp);
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(3, 7) << endl;
}