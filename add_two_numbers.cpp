// https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        int val = 0;
        ListNode *result = NULL;
        ListNode *ptr = NULL;

        while (l1 != NULL && l2 != NULL)
        {
            val = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
            carry = 0;

            if (val > 9)
            {
                val %= 10;
                carry += 1;
            }

            ListNode *temp = new ListNode(val);
            if (result == NULL)
            {
                result = temp;
                ptr = result;
            }
            else
            {
                ptr->next = temp;
                ptr = ptr->next;
            }
        }

        while (l1 != NULL)
        {
            val = l1->val + carry;
            l1 = l1->next;
            carry = 0;

            if (val > 9)
            {
                val %= 10;
                carry += 1;
            }

            ListNode *temp = new ListNode(val);
            ptr->next = temp;
            ptr = ptr->next;
        }

        while (l2 != NULL)
        {
            val = l2->val + carry;
            l2 = l2->next;
            carry = 0;

            if (val > 9)
            {
                val %= 10;
                carry += 1;
            }

            ListNode *temp = new ListNode(val);
            ptr->next = temp;
            ptr = ptr->next;
        }

        if (carry > 0)
        {
            ListNode *temp = new ListNode(carry);
            ptr->next = temp;
            ptr = ptr->next;
        }

        return result;
    }
};

int main()
{
    ListNode *a3 = new ListNode(3);
    ListNode *b3 = new ListNode(4);
    ListNode *a2 = new ListNode(4, a3);
    ListNode *b2 = new ListNode(6, b3);
    ListNode *a1 = new ListNode(2, a2);
    ListNode *b1 = new ListNode(5, b2);

    Solution sol;
    ListNode *result = sol.addTwoNumbers(a1, b1);

    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
}