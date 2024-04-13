// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                long long a, b;
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                switch (tokens[i][0])
                {
                case '+':
                    a += b;
                    break;
                case '-':
                    a -= b;
                    break;
                case '*':
                    a *= b;
                    break;
                case '/':
                    a /= b;
                    break;
                }
                s.push(a);
            }
            else
            {
                bool sign = false;
                int x = 0;
                for (int j = 0; j < tokens[i].size(); j++)
                {
                    if (tokens[i][j] == '-')
                    {
                        sign = true;
                        continue;
                    }
                    int y = int(tokens[i][j]) - 48;
                    x = 10 * x + y;
                }
                if (sign)
                    x *= -1;
                s.push(x);
            }
        }

        return s.top();
    }
};

int main()
{
    vector<string> arr = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "-5", "+"};
    Solution s;
    cout << s.evalRPN(arr) << endl;
}