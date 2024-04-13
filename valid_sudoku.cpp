// https://leetcode.com/problems/valid-sudoku/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i += 3)
        {
            for (int j = 0; j < board[i].size(); j += 3)
            {
                if (!checkBox(board, i, j))
                    return false;
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            if (!checkRow(board, i))
                return false;
        }

        for (int i = 0; i < board.size(); i++)
        {
            if (!checkCol(board, i))
                return false;
        }

        return true;
    }

    bool checkBox(vector<vector<char>> &board, int row, int col)
    {
        unordered_set<char> s;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[row + i][col + j] == '.')
                    continue;
                if (s.find(board[row + i][col + j]) == s.end())
                    s.insert(board[row + i][col + j]);
                else
                    return false;
            }
        }
        return true;
    }

    bool checkRow(vector<vector<char>> &board, int start)
    {
        unordered_set<char> s;
        for (int i = 0; i < board[start].size(); i++)
        {
            if (board[start][i] == '.')
                continue;
            if (s.find(board[start][i]) == s.end())
                s.insert(board[start][i]);
            else
                return false;
        }
        return true;
    }

    bool checkCol(vector<vector<char>> &board, int start)
    {
        unordered_set<char> s;
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][start] == '.')
                continue;
            if (s.find(board[i][start]) == s.end())
                s.insert(board[i][start]);
            else
                return false;
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> a = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                              {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                              {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                              {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                              {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                              {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                              {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                              {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution s;
    cout << s.isValidSudoku(a) << endl;
}