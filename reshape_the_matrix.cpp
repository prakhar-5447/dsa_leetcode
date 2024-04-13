// https://leetcode.com/problems/reshape-the-matrix/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        vector<vector<int>> ans(r, vector<int>(c, 0));
        int currRow = 0, currCol = 0;
        if (mat.size() * mat[0].size() != r * c)
            return mat;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (currCol >= c)
                {
                    currRow++;
                    currCol = 0;
                }
                ans[currRow][currCol++] = mat[i][j];
            }
        }
        return ans;
    }
};

// class Solution
// {
// public:
//     vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
//     {
//         vector<vector<int>> ans;
//         vector<int> temp;
//         int currRow = 0, currCol = 0;
//         if (mat.size() * mat[0].size() != r * c)
//             return mat;

//         for (int i = 0; i < mat.size(); i++)
//         {
//             for (int j = 0; j < mat[i].size(); j++)
//             {
//                 if (currCol >= c)
//                 {
//                     currRow++;
//                     currCol = 0;
//                     ans.push_back(temp);
//                     temp.clear();
//                 }
//                 temp.push_back(mat[i][j]);
//                 currCol++;
//             }
//         }
//         ans.push_back(temp);
//         return ans;
//     }
// };

int main()
{
    vector<vector<int>> a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Solution s;
    vector<vector<int>> ans = s.matrixReshape(a, 4, 3);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}