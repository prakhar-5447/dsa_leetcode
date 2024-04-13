// https://leetcode.com/problems/number-of-islands/description/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), count = 0;
        vector<vector<int>> visited(m, vector<int>(n));

        stack<pair<int, int>> st;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    visited[i][j] = 1;
                    st.push({i, j});
                    count++;

                    while (st.size())
                    {
                        pair<int, int> p = st.top();
                        st.pop();

                        int r = p.first, c = p.second, nRow, nCol;

                        vector<int> rowShift = {-1, 0, +1, 0}, colShift = {0, -1, 0, +1};

                        for (int i = 0; i < 4; ++i)
                        {
                            nRow = r + rowShift[i];
                            nCol = c + colShift[i];

                            if (nRow >= 0 && nCol >= 0 && nRow < m && nCol < n)
                            {
                                if (grid[nRow][nCol] == '1' && !visited[nRow][nCol])
                                {
                                    st.push({nRow, nCol});
                                    visited[nRow][nCol] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
};

int main()
{
    vector<vector<char>> ans = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    Solution s;
    cout << s.numIslands(ans) << endl;
}