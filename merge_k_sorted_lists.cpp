// https://leetcode.com/problems/merge-k-sorted-lists/description/

#include <iostream>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return (a->val > b->val);
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> minheap;

        int K = lists.size();

        if (K == 0)
            return NULL;

        for (int i = 0; i < K; i++)
        {
            if (lists[i] != NULL)
            {
                minheap.push(lists[i]);
            }
        }

        ListNode *head = NULL;
        ListNode *tail = NULL;

        while (minheap.size() > 0)
        {
            ListNode *top = minheap.top();
            minheap.pop();

            if (top->next != NULL)
            {
                minheap.push(top->next);
            }

            if (head == NULL)
            {
                head = top;
                tail = top;
            }
            else
            {
                tail->next = top;
                tail = top;
            }
        }
        return head;
    }
};

int main()
{
    ListNode *r1 = new ListNode(1);
    r1->next = new ListNode(2);
    r1->next->next = new ListNode(3);
    ListNode *r2 = new ListNode(1);
    r2->next = new ListNode(2);
    r2->next->next = new ListNode(3);
    ListNode *r3 = new ListNode(1);
    r3->next = new ListNode(2);
    r3->next->next = new ListNode(3);
    vector<ListNode *> ans = {r1, r2, r3};
    Solution s;
    ListNode *result = s.mergeKLists(ans);
    while (result)
    {
        cout << result->val << endl;
        result = result->next;
    }
}