// https://leetcode.com/problems/insertion-sort-list/description/

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
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        head->next = insertionSortList(head->next);

        if (head->next == NULL)
            return head;
        if (head->val <= head->next->val)
            return head;
        ListNode *temp = head;

        while (temp->next != NULL && head->val > temp->next->val)
        {
            temp = temp->next;
        }

        ListNode *ptr = head->next;
        head->next = temp->next;
        temp->next = head;
        return ptr;
    }
};

int main()
{
    ListNode *ptr = new ListNode(3);
    ptr->next = new ListNode(2);
    ptr->next->next = new ListNode(1);
    Solution s;
    ListNode *ans = s.insertionSortList(ptr);
    while (ans)
    {
        c(ans->val);
        ans = ans->next;
    }
}