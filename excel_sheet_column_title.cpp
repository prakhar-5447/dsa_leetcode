// https://leetcode.com/problems/excel-sheet-column-title/description/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        char ch;
        if (columnNumber <= 26)
        {
            ch = columnNumber + 64;
            string str(1, ch);
            return str;
        }

        int val = (columnNumber % 26);
        if (!val)
        {
            ch = 90;
            string str(1, ch);
            return convertToTitle((columnNumber / 26) - 1) + str;
        }
        else
        {
            ch = val + 64;
            string str(1, ch);
            return convertToTitle(columnNumber / 26) + str;
        }
    }
};

int main()
{
    int n = 345;
    Solution s;
    cout << s.convertToTitle(n) << endl;
}