// https://leetcode.com/problems/excel-sheet-column-number/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int len = columnTitle.length() - 1;
        int count = 0;
        unsigned long long int ans = 0;
        for (int i = len; i >= 0; i--)
        {
            int temp = int(columnTitle[i]) - 64;
            ans = ans + temp * pow(26, count);
            count++;
        }
        return ans;
    }
};

int main()
{
    string str = "ABY";
    Solution s;
    cout << s.titleToNumber(str) << endl;
}