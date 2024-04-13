// https://leetcode.com/problems/pascals-triangle/descripyion/

#include <iostream>
#include <vector>

using namespace std;

int INF = 1e9;
int dp[100][100] = {INF};

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans({0});
        vector<int> temp{};
        ans.push_back({1});

        if (numRows > 1)
            ans.push_back({1, 1});

        int i, j;
        for (i = 2; i < numRows; i++)
        {
            for (j = 0; j <= i / 2; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = 1;
                    temp.push_back(dp[i][j]);
                }
                else
                {
                    int left = ans[i - 1][j - 1];
                    int up = ans[i - 1][j];
                    dp[i][j] = left + up;
                    temp.push_back(dp[i][j]);
                }
            }

            j--;
            if (i % 2 == 0)
                j--;

            for (; j >= 0; j--)
            {
                temp.push_back(dp[i][j]);
            }

            ans.push_back(temp);
            temp.clear();
        }

        return ans;
    }
};

int main()
{
    int row = 5;
    Solution s;

    vector<vector<int>> result = s.generate(row);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}