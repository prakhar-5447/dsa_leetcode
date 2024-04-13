// https://leetcode.com/problems/spiral-matrix/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> ans;
    void rightDown(int rowStart, int rowEnd, int columnStart, int columnEnd, vector<vector<int>> &matrix)
    {
        int i = rowStart, j = columnStart;
        for (; j < columnEnd - 1; j++)
            ans.push_back(matrix[i][j]);

        for (; i < rowEnd; i++)
            ans.push_back(matrix[i][j]);

        if (columnEnd - 1 > columnStart && rowEnd - 1 > rowStart)
            leftUp(rowStart, rowEnd, columnStart, columnEnd, matrix);
    }

    void leftUp(int rowStart, int rowEnd, int columnStart, int columnEnd, vector<vector<int>> &matrix)
    {
        int i = rowEnd - 1, j = columnEnd - 2;
        for (; j > columnStart; j--)
            ans.push_back(matrix[i][j]);

        for (; i > rowStart; i--)
            ans.push_back(matrix[i][j]);

        if (columnEnd - 1 > columnStart + 1 && rowEnd - 1 > rowStart + 1)
            rightDown(rowStart + 1, rowEnd - 1, columnStart + 1, columnEnd - 1, matrix);
    }

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        rightDown(0, matrix.size(), 0, matrix[0].size(), matrix);
        return ans;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    vector<int> ans = s.spiralOrder(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
}