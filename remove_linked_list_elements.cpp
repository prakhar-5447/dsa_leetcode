// https://leetcode.com/problems/remove-linked-list-elements/description/

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head != NULL && head->val == val)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }

        if (head == NULL)
            return head;

        if (head->next == NULL)
            return head;

        ListNode *ptr = head;

        while (ptr != NULL && ptr->next != NULL)
        {
            if (ptr->next->val == val)
            {
                ListNode *temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
            }
            else
                ptr = ptr->next;
        }

        return head;
    }
};

int main()
{
    ListNode *l2 = new ListNode(2);
    ListNode *l1 = new ListNode(1, l2);
    Solution s;

    ListNode *ans = s.removeElements(l1, 1);
    while (ans != NULL)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
}