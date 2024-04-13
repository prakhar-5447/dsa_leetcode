// https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ans = NULL, *p = NULL;
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        while (list1 != NULL && list2 != NULL)
        {

            if (ans == NULL)
            {
                if (list1->val < list2->val)
                {
                    ans = list1;
                    list1 = list1->next;
                }
                else
                {
                    ans = list2;
                    list2 = list2->next;
                }
                p = ans;
                continue;
            }

            if (list1->val < list2->val)
            {
                ans->next = list1;
                list1 = list1->next;
            }
            else
            {
                ans->next = list2;
                list2 = list2->next;
            }
            ans = ans->next;
        }

        while (list1 != NULL)
        {
            ans->next = list1;
            list1 = list1->next;
            ans = ans->next;
        }
        while (list2 != NULL)
        {
            ans->next = list2;
            list2 = list2->next;
            ans = ans->next;
        }

        return p;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2, NULL);
    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(3, NULL);
    Solution s;

    ListNode *ans = s.mergeTwoLists(l1, l2);
    while (ans != NULL)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
}