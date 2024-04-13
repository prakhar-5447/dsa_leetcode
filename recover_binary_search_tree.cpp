// https://leetcode.com/problems/recover-binary-search-tree/description/

#include <iostream>

using namespace std;

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
    void recoverTree(TreeNode *root)
    {
        TreeNode *first, *last, *prev;
        first = NULL;
        prev = NULL;
        last = NULL;

        calpointer(root, &first, &last, &prev);
        if (first && last)
            swap(&(first->val), &(last->val));
    }

    void calpointer(TreeNode *root, TreeNode **first, TreeNode **last, TreeNode **prev)
    {
        if (root == NULL) 
        {
            return;
        }
        calpointer(root->left, first, last, prev);

        if (*prev && root->val < (*prev)->val)
        {
            if (!*first)
            {
                *first = *prev;
                *last = root;
            }
            else
                *last = root;
        }
        *prev = root;
        calpointer(root->right, first, last, prev);
    }

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};

int main()
{
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    Solution s;
    s.recoverTree(t);
}