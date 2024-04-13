// https://leetcode.com/problems/palindrome-linked-list/description/

#include <bits/stdc++.h>

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
    queue<int> q;
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
            return true;

        q.push(head->val);

        if (isPalindrome(head->next))
        {
            if (head->val == q.front())
            {
                q.pop();
                return true;
            }
        }

        return false;
    }
};

int main()
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = NULL;
    Solution s;
    cout << s.isPalindrome(root) << endl;
}