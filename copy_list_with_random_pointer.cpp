// https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> map;
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        if (map.count(head))
            return map[head];

        Node *newNode = new Node(head->val);
        map[head] = newNode;
        newNode->next = copyRandomList(head->next);
        newNode->random = copyRandomList(head->random);
        return newNode;
    }
};

int main()
{
    Solution s;
    cout << s.copyRandomList(NULL) << endl;
}