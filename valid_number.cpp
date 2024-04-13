// https://leetcode.com/problems/valid-number/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        bool exp = false;
        bool sign = false;
        bool decimal = false;
        bool notZero = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (!valid(s[i], notZero))
                return false;
            if ((decimal && s[i] == '.') || (exp && s[i] == '.') || (i == s.length() - 1 && !notZero && sign && s[i] == '.'))
                return false;
            if ((sign || notZero || i == s.length() - 1) && (s[i] == '+' || s[i] == '-'))
                return false;
            if (exp && (s[i] == 'e' || s[i] == 'E'))
                return false;
            if ((i == 0 || i == s.length() - 1 || !notZero) && (s[i] == 'e' || s[i] == 'E'))
                return false;
            if (s[i] == 'e' || s[i] == 'E')
            {
                exp = true;
                decimal = true;
                sign = false;
                notZero = false;
            }
            if (i == 0 && s[i] == '+' || s[i] == '-')
                sign = true;
            if (i == 0 && s.length() - 1 == 0 && s[i] == '.')
                return false;
            if (s[i] == '.')
            {
                decimal = true;
                sign = true;
            }
        }
        return true;
    }

    bool valid(char s, bool &z)
    {
        switch (s)
        {
        case 'e':
            return true;
        case 'E':
            return true;
        case '-':
            return true;
        case '+':
            return true;
        case '.':
            return true;
        }
        int x = (int)s - 48;
        switch (x)
        {
        case 0 ... 9:
            z = true;
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    c(s.isNumber("1E9"));
}