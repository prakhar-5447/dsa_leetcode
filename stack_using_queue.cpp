// https://leetcode.com/problems/implement-stack-using-queues/description/

#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        if (q1.empty())
        {
            return 0;
        }

        int count = -1;

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
            count++;
        }

        while (count)
        {
            q1.push(q2.front());
            q2.pop();
            count--;
        }

        int ans = q2.front();
        q2.pop();

        return ans;
    }

    int top()
    {
        if (q1.empty())
        {
            return 0;
        }
        
        int count = -1;

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
            count++;
        }

        while (count)
        {
            q1.push(q2.front());
            q2.pop();
            count--;
        }

        int ans = q2.front();
        q2.pop();
        q1.push(ans);

        return ans;
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyStack *obj = new MyStack();
    obj->push(10);
    cout << obj->pop() << endl;
    cout << obj->top() << endl;
    if (obj->empty())
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }
}
