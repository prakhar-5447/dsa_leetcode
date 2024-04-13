// https://leetcode.com/problems/min-stack/description/

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack
{
public:
    stack<pair<int, int>> s;
    MinStack()
    {
    }

    void push(int val)
    {
        if (s.empty())
            s.push({val, val});
        else
            s.push({val, min(val, s.top().second)});
    }

    void pop()
    {
        if (!s.empty())
            s.pop();
    }

    int top()
    {
        return s.top().first;
    }

    int getMin()
    {
        return s.top().second;
    }
};

int main()
{
    MinStack s = MinStack();
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
}