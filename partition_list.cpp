// https://leetcode.com/problems/partition-list/description/

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
    ListNode *partition(ListNode *head, int x)
    {
        if (!head)
            return head;

        ListNode *prev = NULL;
        ListNode *s = head;
        ListNode *e = head;
        ListNode *temp = NULL;
        while (e)
        {
            while (s->val < x)
            {
                prev = s;
                s = s->next;
                if (!s || !s->next)
                    return head;
            }
            e = s->next;
            if (!e)
                return head;
            if (e->val < x)
            {
                if (prev)
                    prev->next = e;
                else
                    head = e;
                s->next = e->next;
                e->next = s;
                prev = e;
            }
            else
            {
                if (!e->next)
                    return head;
                temp = e->next;
                while (temp->val >= x)
                {
                    e = temp;
                    temp = temp->next;
                    if (!temp)
                        return head;
                }
                if (!prev)
                    head = temp;
                else
                    prev->next = temp;
                e->next = temp->next;
                temp->next = s;
                prev = temp;
                s = temp->next;
                temp = e->next;
            }
        }
        return head;
    }
};

int main()
{
    ListNode *root = new ListNode(3);
    root->next = new ListNode(1);
    root->next->next = new ListNode(2);
    Solution s;
    ListNode *ans = s.partition(root, 3);
    while (ans)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
}