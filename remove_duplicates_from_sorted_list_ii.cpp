// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

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
        if (!head)
            return head;
        int LastDuplicate = -101;
        ListNode *prev = NULL, *curr = head, *nxt = curr->next;
        while (curr)
        {
            if (nxt && curr->val == nxt->val)
            {
                LastDuplicate = curr->val;
                if (prev)
                {
                    prev->next = curr->next;
                    curr = prev->next;
                }
                else
                {
                    head = head->next;
                    curr = head;
                }
                nxt = curr->next;
            }
            else if (curr->val == LastDuplicate)
            {
                if (prev)
                {
                    prev->next = curr->next;
                    curr = prev->next;
                }
                else
                {
                    head = head->next;
                    curr = head;
                }
                if (curr)
                    nxt = curr->next;
                else
                    return head;
            }
            else
            {
                prev = curr;
                curr = nxt;
                if (curr)
                    nxt = curr->next;
                else
                    return head;
            }
        }
        return head;
    }
};

int main()
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(3);
    root->next->next->next->next = new ListNode(3);
    root->next->next->next->next->next = new ListNode(4);
    Solution s;
    ListNode *ans = s.deleteDuplicates(root);
    while (ans)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
}