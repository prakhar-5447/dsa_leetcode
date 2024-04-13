// https://leetcode.com/problems/n-queens-ii/description/

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
    int count = 0;
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

    void solve(int col, vector<string> &board, int n)
    {
        if (col == n)
        {
            count++;
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, n);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        solve(0, board, n);
        return count;
    }
};

int main()
{
    Solution s;
    c(s.totalNQueens(5));
}