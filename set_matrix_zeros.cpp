// https://leetcode.com/problems/set-matrix-zeroes/description/

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
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<vector<int>> zero(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] != 0)
                    continue;
                zero[i][j] = 1;
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] != 0)
                    continue;
                if (zero[i][j])
                {
                    rowZeros(matrix, i, zero);
                    colZeros(matrix, j, zero);
                }
            }
        }
    }

    void rowZeros(vector<vector<int>> &matrix, int row, vector<vector<int>> &zero)
    {
        for (int i = 0; i < matrix[row].size(); i++)
            matrix[row][i] = 0;
    }

    void colZeros(vector<vector<int>> &matrix, int col, vector<vector<int>> &zero)
    {
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][col] = 0;
    }
};

int main()
{
    vii a = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    Solution s;
    s.setZeroes(a);
    f(i, 0, a.size())
    {
        f(j, 0, a[i].size())
        {
            c(a[i][j]);
        }
        c(" ");
    }
}