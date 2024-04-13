// https://leetcode.com/problems/base-7/description/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    void reverseStr(string &str)
    {
        int n = str.length();
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
    }

    string convertToBase7(int num)
    {
        bool negative = false;

        if (num == 0)
            return to_string(0);

        if (num < 0)
        {
            negative = true;
            num *= -1;
        }

        string temp;
        while (num)
        {
            temp.append(to_string(num % 7));
            num /= 7;
        }

        if (negative)
            temp.append("-");
        reverseStr(temp);

        return temp;
    }
};

int main()
{
    Solution s;
    string ans = s.convertToBase7(-7);
    for (int i = 0; i < ans.length(); i++)
    {
        cout << ans[i];
    }
}