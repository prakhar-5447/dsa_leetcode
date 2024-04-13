// https://leetcode.com/problems/n-queens/description/

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
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int x = row;
        int y = col;
        while (y >= 0)
        {
            if (board[x][y] == 'Q')
                return false;
            y--;
        }

        x = row;
        y = col;

        while (x >= 0 && y >= 0)
        {
            if (board[x][y] == 'Q')
                return false;
            x--;
            y--;
        }

        x = row;
        y = col;

        while (x < n && y >= 0)
        {
            if (board[x][y] == 'Q')
                return false;
            x++;
            y--;
        }

        return true;
    }

    void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {

        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0, ans, board, n);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> ans = s.solveNQueens(5);
    f(i, 0, ans.size())
    {
        f(j, 0, ans[i].size())
        {
            cout << ans[i][j] << " " << endl;
        }
        cout << endl;
    }
}