// https://leetcode.com/problems/longest-valid-parentheses/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int res = 0;
        stack<int> stk;
        stk.push(-1);
        int i = 0;
        while (i < s.length())
        {
            if (s[i] == '(')
                stk.push(i);
            else
            {
                stk.pop();
                if (stk.empty())
                    stk.push(i);
                else
                    res = max(res, i - stk.top());
            }
            i++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.longestValidParentheses("(()()") << endl;
}