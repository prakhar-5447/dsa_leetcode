// https://leetcode.com/problems/reverse-linked-list-ii/description/

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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL or head->next == NULL)
            return head;
        ListNode *temp = reverseList(head->next);
        ListNode *ptr = temp;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = head;
        head->next = NULL;
        return temp;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *curr = head, *prev = NULL;
        int count = 1;

        while (count != left)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        ListNode *start = curr;
        while (count != right)
        {
            curr = curr->next;
            count++;
        }

        ListNode *rest = curr->next;
        curr->next = NULL;
        ListNode *newhead = reverseList(start);
        if (prev != NULL)
            prev->next = newhead;

        start->next = rest;
        if (left == 1)
            return newhead;

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
    ListNode *newNode = s.reverseBetween(root, 1, 2);
    while (newNode != NULL)
    {
        cout << newNode->val << endl;
        newNode = newNode->next;
    }
}