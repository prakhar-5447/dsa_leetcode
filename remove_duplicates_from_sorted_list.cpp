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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *i = head;
        ListNode *j = head->next;

        while (j != NULL)
        {
            if (i->val == j->val)
            {
                j = j->next;
            }
            else
            {
                i->next = j;
                i = j;
                j = j->next;
            }
        }

        i->next = NULL;
        return head;
    }
};

int main()
{
    ListNode *l2 = new ListNode(2);
    ListNode *l1 = new ListNode(1, l2);
    Solution s;

    ListNode *ans = s.deleteDuplicates(l1);
    while (ans != NULL)
    {
        cout << ans->val << endl;
        ans = ans->next;
}
}