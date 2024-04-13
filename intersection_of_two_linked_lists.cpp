// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

#include <iostream>
#include <string>
#include <map>

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        map<ListNode *, int> visited;
        while (headA != NULL)
        {
            visited[headA] = headA->val;
            headA = headA->next;
        }
        while (headB != NULL)
        {
            if (visited[headB] == headB->val)
                return headB;
            visited[headB] = headB->val;
            headB = headB->next;
        }
        return NULL;
    }
};

int main()
{
    ListNode *root1 = new ListNode(1);
    root1->next = new ListNode(2);
    root1->next->next = new ListNode(3);
    ListNode *root2 = new ListNode(1);
    root2->next = root1->next;
    Solution s;
    cout << s.getIntersectionNode(root1, root2) << endl;
}