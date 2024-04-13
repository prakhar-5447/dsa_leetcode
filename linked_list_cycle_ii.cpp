// https://leetcode.com/problems/linked-list-cycle-ii/description/

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
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return NULL;

        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        if (fast == NULL || fast->next == NULL)
            return NULL;

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};

int main()
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = root->next;
    Solution s;
    cout << s.detectCycle(root)->val << endl;
}