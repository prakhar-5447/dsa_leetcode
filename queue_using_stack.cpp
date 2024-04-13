// https://leetcode.com/problems/implement-queue-using-stacks/description

#include <iostream>
#include <stack>

using namespace std;

// class MyQueue
// {
// public:
//     stack<int> s1, s2;
//     MyQueue()
//     {
//     }

//     void push(int x)
//     {
//         s1.push(x);
//     }

//     int pop()
//     {
//         while (!s1.empty())
//         {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         int x = s2.top();
//         s2.pop();

//         while (!s2.empty())
//         {
//             s1.push(s2.top());
//             s2.pop();
//         }

//         return x;
//     }

//     int peek()
//     {
//         while (!s1.empty())
//         {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         int x = s2.top();

//         while (!s2.empty())
//         {
//             s1.push(s2.top());
//             s2.pop();
//         }

//         return x;
//     }

//     bool empty()
//     {
//       return s1.empty();
//     }
// };

class MyQueue
{
public:
    stack<int> s1, s2;
    bool stackQueue = false;

    MyQueue()
    {
    }

    void push(int x)
    {
        if (stackQueue)
        {
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            s1.push(x);
            stackQueue = false;
        }
        else
            s1.push(x);
    }

    int pop()
    {
        int x;
        if (this->empty())
            return 0;
        

        if (stackQueue)
        {
            x = s2.top();
            s2.pop();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            x = s2.top();
            s2.pop();
            stackQueue = true;
        }
        return x;
    }

    int peek()
    {
        int x;
        if (this->empty())
            return 0;
        

        if (stackQueue)
        {
            x = s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            x = s2.top();
            stackQueue = true;
        }
        return x;
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

int main()
{
    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << obj->pop() << endl;
    cout << obj->peek() << endl;
    cout << obj->peek() << endl;
    cout << obj->empty() << endl;
}