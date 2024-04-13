// https://leetcode.com/problems/rotate-image/description/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<vector<int>> temp(row, vector<int>(column, 0));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
                temp[j][row - i - 1] = matrix[i][j];
        }

        matrix = temp;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    s.rotate(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}