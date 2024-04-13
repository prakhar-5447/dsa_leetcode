// https://leetcode.com/problems/swap-nodes-in-pairs/description/

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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *temp = swapPairs(head->next->next);
        ListNode *end = head->next;
        head->next = temp;
        end->next = head;
        return end;
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
    ListNode *ans = s.swapPairs(root);
    while (root)
    {
        cout << root->val << endl;
        root = root->next;
    }
}