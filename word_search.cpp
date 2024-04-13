// https://leetcode.com/problems/word-search/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool exist(int i, int j, vector<vector<bool>> &dp, vector<vector<char>> &board, string &word, int index)
    {
        if (index == word.length())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j > board[0].size())
            return false;

        if (dp[i][j])
            return false;

        if (word[index] != board[i][j])
            return false;

        dp[i][j] = true;
        if (exist(i - 1, j, dp, board, word, index + 1))
            return true;
        if (exist(i, j - 1, dp, board, word, index + 1))
            return true;
        if (exist(i + 1, j, dp, board, word, index + 1))
            return true;
        if (exist(i, j + 1, dp, board, word, index + 1))
            return true;
        dp[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int i, j;
        for (i = 0; i < board.size(); i++)
        {
            for (j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    vector<vector<bool>> dp(board.size(), vector<bool>(board[0].size(), false));
                    if (exist(i, j, dp, board, word, 0))
                        return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    vector<vector<char>> arr = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution s;
    cout << s.exist(arr, "ABCCED") << endl;
}