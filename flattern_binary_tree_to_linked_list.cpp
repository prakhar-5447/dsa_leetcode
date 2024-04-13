// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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
    void flatten(TreeNode *root)
    {

        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        if (root->left != NULL)
        {
            flatten(root->left);

            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = NULL;

            TreeNode *T = root->right;
            while (T->right != NULL)
                T = T->right;
            T->right = temp;
        }
        flatten(root->right);
    }

    void traverse(TreeNode *root)
    {
        if (root == NULL)
            return;

        cout << root->val;
        traverse(root->right);
    }
};

int main()
{
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    Solution s;
    s.flatten(t);
    s.traverse(t);
}