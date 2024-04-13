// https://leetcode.com/problems/reorder-list/description/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        vector<ListNode *> v;
        ListNode *temp = head;
        while (temp != NULL)
        {
            v.push_back(temp);
            temp = temp->next;
        };
        int i = 0, j = v.size() - 1;
        head = v[i];
        head->next = v[j];
        i++;
        temp = head->next;
        while (j > i)
        {
            temp->next = v[i];
            temp = temp->next;
            j--;
            temp->next = v[j];
            temp = temp->next;
            i++;
        }
        temp->next = NULL;
    }
};

int main()
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);

    ListNode *ptr;
    ptr = root;

    while (ptr)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }

    Solution s;
    s.reorderList(root);
    ptr = root;
    cout << endl;

    while (ptr)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
}