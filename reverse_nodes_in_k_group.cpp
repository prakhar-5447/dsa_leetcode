// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

#include <bits/stdc++.h>

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        ListNode *currCheck = head;

        for (int i = 0; i < k; i++)
        {
            if (currCheck == NULL)
                return head;

            currCheck = currCheck->next;
        }

        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nxt = NULL;

        for (int i = 0; i < k; i++)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};

int main()
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode *ans = s.reverseKGroup(root, 2);
    while (ans)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
}