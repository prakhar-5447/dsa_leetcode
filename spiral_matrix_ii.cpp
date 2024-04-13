// https://leetcode.com/problems/spiral-matrix-ii/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rightDown(int rowStart, int rowEnd, int columnStart, int columnEnd, vector<vector<int>> &matrix, int count)
    {
        int i = rowStart, j = columnStart;
        for (; j < columnEnd - 1; j++)
            matrix[i][j] = count++;

        for (; i < rowEnd; i++)
            matrix[i][j] = count++;

        if (columnEnd - 1 > columnStart && rowEnd - 1 > rowStart)
            leftUp(rowStart, rowEnd, columnStart, columnEnd, matrix, count);
    }

    void leftUp(int rowStart, int rowEnd, int columnStart, int columnEnd, vector<vector<int>> &matrix, int count)
    {
        int i = rowEnd - 1, j = columnEnd - 2;
        for (; j > columnStart; j--)
            matrix[i][j] = count++;

        for (; i > rowStart; i--)
            matrix[i][j] = count++;

        if (columnEnd - 1 > columnStart + 1 && rowEnd - 1 > rowStart + 1)
            rightDown(rowStart + 1, rowEnd - 1, columnStart + 1, columnEnd - 1, matrix, count);
    }

    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        rightDown(0, matrix.size(), 0, matrix[0].size(), matrix, 1);
        return matrix;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> ans = s.generateMatrix(3);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}