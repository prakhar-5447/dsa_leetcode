// https://leetcode.com/problems/rotate-list/description/

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (k == 0 || !head)
            return head;
        int count = 0;
        ListNode *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        temp = head;
        k = k % count;
        int i = count - k - 1;
        while (i > 0)
        {
            temp = temp->next;
            i--;
        }
        ListNode *startIndex = temp;
        while (startIndex->next != NULL)
        {
            startIndex = startIndex->next;
        }
        startIndex->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};

int main()
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = NULL;
    Solution s;
    ListNode *newNode = s.rotateRight(root, 1);
    while (newNode != NULL)
    {
        cout << newNode->val << endl;
        newNode = newNode->next;
    }
}