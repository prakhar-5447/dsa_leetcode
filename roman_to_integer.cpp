// https://leetcode.com/problems/roman-to-integer/description/

#include <iostream>

using namespace std;

class Solution
{
public:
    bool valid(int index, int length, string s)
    {
        if (index + 1 > length)
            return true;

        if (s[index] == 'I')
        {
            if (s[index + 1] == 'V' || s[index + 1] == 'X')
                return false;
        }
        else if (s[index] == 'X')
        {
            if (s[index + 1] == 'L' || s[index + 1] == 'C')
                return false;
        }
        else if (s[index] == 'C')
        {
            if (s[index + 1] == 'M' || s[index + 1] == 'D')
                return false;
        }
        return true;
    }

    int value(char s)
    {
        switch (s)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        return 0;
    }

    int romanToInt(string s)
    {
        int ans = 0;
        int len = s.length() - 1;
        for (int i = len; i >= 0; i--)
        {
            if (valid(i, len, s))
                ans += value(s[i]);
            else
                ans -= value(s[i]);
        }
        return ans;
    }
};

int main()
{
    string x;
    cin >> x;
    Solution s;
    cout << "value is " << s.romanToInt(x) << endl;
}
