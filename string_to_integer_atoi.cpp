// https://leetcode.com/problems/string-to-integer-atoi/description/

#include <iostream>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int ans = 0, i = 0;
        bool negative = false;

        while (i < s.length() && s[i] == ' ')
            i++;

        if (s[i] == '-' || s[i] == '+')
        {
            i++;
            if (s[i] >= 48 && s[i] <= 57)
            {
                if (s[i - 1] == '-')
                {
                    negative = true;
                    ans -= (s[i] - '0');
                    i++;
                }
            }
            else
                return ans;
        }

        for (; i < s.length(); i++)
        {
            if (s[i] >= 48 && s[i] <= 57)
            {
                if (negative)
                {
                    if ((INT_MIN + (s[i] - '0')) / 10 > ans)
                        return INT_MIN;
                    ans = ans * 10 - (s[i] - '0');
                }
                else
                {
                    if ((INT_MAX - (s[i] - '0')) / 10 < ans)
                        return INT_MAX;
                    ans = ans * 10 + (s[i] - '0');
                }
            }
            else
                break;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.myAtoi("   42") << endl;
}