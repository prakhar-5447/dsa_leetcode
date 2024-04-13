// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int count = -1;
        ListNode *temp = head;

        while (temp)
        {
            count++;
            temp = temp->next;
        }

        count -= n;
        if (count < 0)
        {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        temp = head;
        while (count)
        {
            temp = temp->next;
            count--;
        }
        ListNode *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;

        return head;
    }
};

int main()
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    Solution s;
    ListNode *ans = s.removeNthFromEnd(root, 2);
    while (ans)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
}