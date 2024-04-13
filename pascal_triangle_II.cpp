// https://leetcode.com/problems/pascals-triangle-ii/description/

#include <iostream>
#include <vector>

using namespace std;

int INF = 1e9;
int dp[100] = {INF};

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans{1};
        vector<int> temp{};

        if (rowIndex >= 1)
            ans = {1, 1};

        int i, j;
        for (i = 2; i <= rowIndex; i++)
        {
            for (j = 0; j <= i / 2; j++)
            {
                if (j == 0)
                {
                    dp[j] = 1;
                    temp.push_back(dp[j]);
                }
                else
                {
                    int left = ans[j - 1];
                    int up = ans[j];
                    dp[j] = left + up;
                    temp.push_back(dp[j]);
                }
            }

            j--;
            if (i % 2 == 0)
                j--;

            for (; j >= 0; j--)
            {
                temp.push_back(dp[j]);
            }

            ans = temp;
            temp.clear();
        }

        return ans;
    }
};

int main()
{
    int row = 5;
    Solution s;

    vector<int> result = s.getRow(row);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}