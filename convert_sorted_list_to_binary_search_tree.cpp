// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> getArray(ListNode *head)
    {
        vector<int> ans;
        while (head)
        {
            ans.push_back(head->val);
            head = head->next;
        }
        return ans;
    }

    TreeNode *createBinarySearchTree(TreeNode *root, vector<int> &arr, int s, int e)
    {
        if (s > e)
            return NULL;
        int mid = s + (e - s) / 2;
        root = new TreeNode(arr[mid]);
        root->left = createBinarySearchTree(root->left, arr, s, mid - 1);
        root->right = createBinarySearchTree(root->right, arr, mid + 1, e);
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        TreeNode *root = NULL;
        vector<int> arr = getArray(head);
        return createBinarySearchTree(root, arr, 0, arr.size() - 1);
    }

    void traverse(TreeNode *root)
    {
        if (root == NULL)
            return;

        traverse(root->left);
        cout << root->val << endl;
        traverse(root->right);
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution s;
    TreeNode *ptr = s.sortedListToBST(head);
    s.traverse(ptr);
}