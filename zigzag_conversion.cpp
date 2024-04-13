// https://leetcode.com/problems/zigzag-conversion/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {

        if (numRows == 1)
            return s;
        vector<string> ans(numRows);
        string res;
        int len = s.length();
        for (int i = 0, rowCount = 0; i < len; i++)
        {
            ans[rowCount].push_back(s[i]);
            rowCount++;
            if (rowCount == numRows)
            {
                rowCount -= 2;
                i++;
                while (rowCount > 0 && i < len)
                {
                    ans[rowCount].push_back(s[i]);
                    rowCount--;
                    i++;
                }
                i--;
            }
        }

        for (int i = 0; i < ans.size(); i++)
            res.append(ans[i]);

        return res;
    }
};

int main()
{
    Solution s;
    string ans = s.convert("AB", 1);
    cout << ans << endl;
}