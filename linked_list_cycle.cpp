// https://leetcode.com/problems/linked-list-cycle/description/

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *p = head, *q = head;
        while (p != NULL)
        {
            p = p->next;
            if (p == NULL)
                return false;
            p = p->next;
            q = q->next;
            if (p == q)
                return true;
        }
        return false;
    }
};

int main()
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = root->next;
    Solution s;
    cout << s.hasCycle(root) << endl;
}
