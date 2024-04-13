// https://leetcode.com/problems/valid-parentheses/description/

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    stack<char> balance;
    bool isValid(string s)
    {
        int strLen = s.length();

        for (int i = 0; i < strLen; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                balance.push(s[i]);
            else
            {
                if (balance.empty())
                {
                    balance.push(s[i]);
                    break;
                }

                if (balance.top() == '(' && s[i] == ')' || balance.top() == '{' && s[i] == '}' || balance.top() == '[' && s[i] == ']')
                    balance.pop();
                else
                    break;
            }
        }

        return balance.empty();
    }
};

int main()
{
    Solution sol;
    string s = "({}[{}])";

    if (sol.isValid(s))
        cout << "parentheses are balanced" << endl;
    else
        cout << "parentheses are not balanced" << endl;
}