// https://leetcode.com/problems/reverse-linked-list/description/

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
        if (head == NULL)
            return head;

        if (head->next != NULL)
        {
            ListNode *temp = reverseList(head->next);
            ListNode *ptr = temp;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = head;
            head->next = NULL;
            return temp;
        }

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
    ListNode *newNode = s.reverseList(root);
    while (newNode != NULL)
    {
        cout << newNode->val << endl;
        newNode = newNode->next;
    }
}