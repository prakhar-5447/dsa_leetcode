// https://leetcode.com/problems/invert-binary-tree/description/

#include <bits/stdc++.h>

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return root;

        TreeNode *temp = invertTree(root->right);
        root->right = invertTree(root->left);
        root->left = temp;

        return root;
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
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    Solution s;
    TreeNode *ans = s.invertTree(t);
    s.traverse(ans);
}